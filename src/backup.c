/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumedi <ssumedi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:39:34 by ssumedi           #+#    #+#             */
/*   Updated: 2017/11/20 19:48:03 by ssumedi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../include/fillit.h"

/*ft_error.c*/

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(-1);
}

void	ft_usage_message(void)
{
	ft_putstr("usage: fillit file\n");
	exit(-1);
}

/*ft_check_input.c*/

int		ft_check_input(char *str)
{
	int		i;
	int		blk;
	int		mty;
	int		nl;

	i = -1;
	blk = 0;
	mty = 0;
	nl = 0;
	while (str[++i])
	{
		if (str[i] == '#')
			blk++;
		else if (str[i] == '.')
			mty++;
		else if (str[i] == '\n')
			nl++;
		else
			ft_error();
		if ((str[i] == '\n' && str[i - 1] == '\n') && (nl % 5) != 0)
			ft_error();
	}
	if (blk % 4 != 0 || blk < 4 || mty % 12 != 0 || nl != ((blk / 4) - 1) + blk)
		ft_error();
	return (blk / 4);
}

/*ft_read_input.c*/

char	*ft_read_input(char *input)
{
	int		fd;
	int		ret;
	char	buf[546];
	char	*str;

	fd = open(input, O_RDONLY);
	if (fd == -1)
		ft_error();
	while ((ret = read(fd, buf, sizeof(buf))))
		str = ft_strdup(buf);
	if (!str || close(fd) == -1)
		ft_error();
	return (str);
}

/*ft_identify.c*/

int		ft_compare(int *coords, int a, int b, int c)
{
	if (coords[0] == a && coords[1] == b && coords[2] == c)
		return (1);
	return (0);
}

int		ft_check_coords(int *coords)
{
	if (ft_compare(coords, 1, 5, 6) || ft_compare(coords, 5, 9, 10) ||
		ft_compare(coords, 5, 6, 7) || ft_compare(coords, 1, 5, 10) ||
		ft_compare(coords, 1, 2, 7) || ft_compare(coords, 5, 10, 11) ||
		ft_compare(coords, 1, 2, 5) || ft_compare(coords, 1, 6, 11) ||
		ft_compare(coords, 3, 4, 5) || ft_compare(coords, 1, 6, 7) ||
		ft_compare(coords, 4, 5, 9) || ft_compare(coords, 1, 4, 5) ||
		ft_compare(coords, 5, 6, 11) || ft_compare(coords, 1, 2, 3) ||
		ft_compare(coords, 5, 10, 15) || ft_compare(coords, 4, 5, 6) ||
		ft_compare(coords, 5, 6, 10) || ft_compare(coords, 1, 2, 6) ||
		ft_compare(coords, 4, 5, 10))
		return (1);
	return (0);
}

int		*ft_return_coords(char *str, int i)
{
	int		temp;
	int		count;
	int		x;
	int		*coords;

	temp = i;
	count = 0;
	x = 0;
	coords = (int*)malloc(sizeof(int) * 3);
	while (str[++temp] && count < 3)
	{
		if (str[temp] == '#')
		{
			coords[x] = temp - i;
			x++;
			count++;
		}
	}
	if (!ft_check_coords(coords))
	{
		free(coords);
		ft_error();
		return (0);
	}
	return (coords);
}

int		**ft_identify(char *str, int count)
{
	int		i;
	int		x;
	int		**tetro;

	i = -1;
	x = 0;
	tetro = (int**)malloc(sizeof(int) * 3 * count);
	while (str[++i])
	{
		if (str[i] == '#')
		{
			if ((tetro[x++] = ft_return_coords(str, i)))
				i = (x * 21) - 1;
			else
			{
				x = 0;
				while (tetro[x++])
					free(tetro[x]);
				return (0);
			}
		}
	}
	return (tetro);
}

/*ft_grid*/

char	*ft_grid(int size)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	str = (char*)malloc(sizeof(char) * ((size * (size + 1)) + 1));
	while (++i < (size * (size + 1)))
	{
		j = -1;
		while (++j < size)
		{
			str[i] = '.';
			i++;
		}
		str[i] = '\n';
	}
	str[i] = '\0';
	return (str);
}

/*ft_solve.c*/

int		ft_is_available(char *str, int i, int *coords)
{
	if (str[i] == '.' && str[i + coords[0]] == '.' &&
			str[i + coords[1]] == '.' && str[i + coords[2]] == '.')
		return (1);
	return (0);
}

char	*ft_print(char *str, int i, int *coords, char c)
{
	str[i] = c;
	str[i + coords[0]] = c;
	str[i + coords[1]] = c;
	str[i + coords[2]] = c;
	return (str);
}

int		**ft_scale(int **tetro, int size, int x)
{
	while (tetro[++x])
	{
		if (tetro[x][0] == (size - 2) && tetro[x][1] == (size - 1) &&
				tetro[x][2] == size)
		{
			tetro[x][0] += 1;
			tetro[x][1] += 1;
			tetro[x][2] += 1;
		}
		else if ((tetro[x][0] == (size - 1) || tetro[x][1] == (size - 1) ||
				tetro[x][2] == (size - 1)) || (tetro[x][0] == size &&
				tetro[x][1] == ((size * 2) - 1) && tetro[x][2] == (size * 2)))
		{
			tetro[x][0] += (tetro[x][0] / (size - 1));
			tetro[x][1] += (tetro[x][1] / (size - 1));
			tetro[x][2] += (tetro[x][2] / (size - 1));
		}
		else
		{
			tetro[x][0] += (tetro[x][0] / size);
			tetro[x][1] += (tetro[x][1] / size);
			tetro[x][2] += (tetro[x][2] / size);
		}
	}
	return (tetro);
}

int		ft_solve(int **tetro, int x, int *n, char *str)
{
	int		i;

	if (x == n[1] || !str[x])
	{
		ft_putstr(str);
		exit(1);
	}
	i = -1;
	while (str[++i])
	{
		if (ft_is_available(str, i, tetro[x]))
		{
			str = ft_print(str, i, tetro[x], 'A' + x);
			ft_solve(tetro, x + 1, n, str);
			str = ft_print(str, i, tetro[x], '.');
		}
	}
	if (x == 0)
	{
		n[0] += 1;
		return (ft_solve(ft_scale(tetro, n[0], -1), 0, n, ft_grid(n[0])));
	}
	return (0);
}

/*main.c*/

int		main(int argc, char **argv)
{
	char	*read;
	int		check_input;
	int		**identify_tetriminos;
	int		*n;
	int		solve;

	if (argc == 2)
	{
		read = ft_read_input(argv[1]);
		check_input = ft_check_input(read);
		identify_tetriminos = ft_identify(read, check_input);
		n = (int*)malloc(sizeof(int) * 2);
		n[0] = 4;
		n[1] = check_input;
		solve = ft_solve(identify_tetriminos, 0, n, ft_grid(4));
	}
	else
		ft_usage_message();
	return (0);
}
