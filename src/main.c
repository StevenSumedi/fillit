/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumedi <ssumedi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:39:34 by ssumedi           #+#    #+#             */
/*   Updated: 2017/11/02 17:36:06 by ssumedi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include "../include/fillit.h"

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(-1);
}

void	ft_error_usage(void)
{
	ft_putstr("usage: fillit file\n");
	exit(-1);
}

int		ft_check_valid(char *str)
{
	int		i;
	int		po;
	int		pe;
	int		line;

	i = -1;
	po = 0;
	pe = 0;
	line = 0;
	while (str[++i])
	{
		if (str[i] == '#')
			po++;
		else if (str[i] == '.')
			pe++;
		else if (str[i] == '\n')
			line++;
		else
			ft_error();
		if ((str[i] == '\n' && str[i - 1] == '\n') && (line % 5) != 0)
			ft_error();
	}
	if (po % 4 != 0 || po < 4 || pe % 12 != 0 || line != ((po / 4) - 1) + po)
		ft_error();
	return (po / 4);
}

char	*ft_read_input(char *input)
{
	int		fd;
	int		ret;
	char	buf[545];
	char	*str;

	fd = open(input, O_RDONLY);
	if (fd == -1)
		ft_error();
	while ((ret = read(fd, buf, sizeof(buf))))
		str = ft_strdup(buf);
	if (close(fd) == -1)
		ft_error();
	if (str == '\0')
		ft_error();
	return (str);
}

int		ft_isshape(int *array, int a, int b, int c)
{
	if (array[0] == a && array[1] == b && array[2] == c)
		return (1);
	return (0);
}

int		ft_tetrimino_check(int *array)
{
	if (ft_isshape(array, 1, 5, 6))
		return (ft_isshape(array, 1, 5, 6));
	if (ft_isshape(array, 5, 9, 10))
		return (ft_isshape(array, 5, 9, 10));
	if (ft_isshape(array, 5, 6, 7))
		return (ft_isshape(array, 5, 6, 7));
	if (ft_isshape(array, 1, 5, 10))
		return (ft_isshape(array, 1, 5, 10));
	if (ft_isshape(array, 1, 2, 7))
		return (ft_isshape(array, 1, 2, 7));
	if (ft_isshape(array, 5, 10, 11))
		return (ft_isshape(array, 5, 10, 11));
	if (ft_isshape(array, 1, 2, 5))
		return (ft_isshape(array, 1, 2, 5));
	if (ft_isshape(array, 1, 6, 11))
		return (ft_isshape(array, 1, 6, 11));
	if (ft_isshape(array, 3, 4, 5))
		return (ft_isshape(array, 3, 4, 5));
	if (ft_isshape(array, 1, 6, 7))
		return (ft_isshape(array, 1, 6, 7));
	return (0);
}

int		ft_tetrimino_check_two(int *array)
{
	if (ft_isshape(array, 4, 5, 9))
		return (ft_isshape(array, 4, 5, 9));
	if (ft_isshape(array, 1, 4, 5))
		return (ft_isshape(array, 1, 4, 5));
	if (ft_isshape(array, 5, 6, 11))
		return (ft_isshape(array, 5, 6, 11));
	if (ft_isshape(array, 1, 2, 3))
		return (ft_isshape(array, 1, 2, 3));
	if (ft_isshape(array, 5, 10, 15))
		return (ft_isshape(array, 5, 10, 15));
	if (ft_isshape(array, 4, 5, 6))
		return (ft_isshape(array, 4, 5, 6));
	if (ft_isshape(array, 5, 6, 10))
		return (ft_isshape(array, 5, 6, 10));
	if (ft_isshape(array, 1, 2, 6))
		return (ft_isshape(array, 1, 2, 6));
	if (ft_isshape(array, 4, 5, 10))
		return (ft_isshape(array, 4, 5, 10));
	return (0);
}

int		*ft_tetrimino(char *str, int i)
{
	int		*array;
	int		x;
	int		temp;
	int		count;

	x = 0;
	temp = i;
	count = 0;
	array = (int*)malloc(sizeof(int) * 3);
	while (str[++temp] && count < 3)
	{
		if (str[temp] == '#')
		{
			array[x] = temp - i;
			x++;
			count++;
		}
	}
	if (ft_tetrimino_check(array) || ft_tetrimino_check_two(array))
		return (array);
	free(array);
	ft_error();
	return (0);
}

int		**ft_identify(char *str, int count)
{
	int		i;
	int		x;
	int		**tetriminos;

	i = -1;
	x = 0;
	tetriminos = (int**)malloc(sizeof(int) * 3 * count);
	while (str[++i] != '\0')
	{
		if (str[i] == '#')
		{
			if ((tetriminos[x++] = ft_tetrimino(str, i)) != 0)
				i = (x * 21) - 1;
			else
			{
				x = 0;
				while (tetriminos[x++])
					free(tetriminos[x]);
				return (0);
			}
		}
	}
	return (tetriminos);
}

char	*ft_grd(int size)
{
	int		i;
	int		j;
	char	*output;

	i = 0;
	j = 0;
	output = (char*)malloc(sizeof(char) * ((size * (size + 1)) + 1));
	while (i < (size * (size + 1)))
	{
		while (j < size)
		{
			output[i] = '.';
			i++;
			j++;
		}
		output[i] = '\n';
		i++;
		j = 0;
	}
	output[i] = '\0';
	return (output);
}

int		ft_isavailable(char *str, int i, int *array)
{
	if (str[i] == '.' && str[i + array[0]] == '.' &&
			str[i + array[1]] == '.' && str[i + array[2]] == '.')
		return (1);
	return (0);
}

char	*ft_print(char *str, int i, int *array, int count)
{
	while (str[i])
	{
		if (ft_isavailable(str, i, array))
		{
			str[i] = 'A' + count;
			str[i + array[0]] = 'A' + count;
			str[i + array[1]] = 'A' + count;
			str[i + array[2]] = 'A' + count;
			return (str);
		}
		i++;
	}
	return (0);
}

char	*ft_unprint(char *str, int i, int *array)
{
	str[i] = '.';
	str[i + array[0]] = '.';
	str[i + array[1]] = '.';
	str[i + array[2]] = '.';
	return (str);
}

int		**ft_mod(int **array, int size, int x)
{
	while (array[++x])
	{
		if (array[x][0] == (size - 2) && array[x][1] == (size - 1) &&
				array[x][2] == (size))
		{
			array[x][0] += 1;
			array[x][1] += 1;
			array[x][2] += 1;
		}
		else if ((array[x][0] == (size - 1) || array[x][1] == (size - 1) ||
				array[x][2] == (size - 1)) || (array[x][0] == size &&
				array[x][1] == ((size * 2) - 1) && array[x][2] == (size * 2)))
		{
			array[x][0] += (array[x][0] / (size - 1));
			array[x][1] += (array[x][1] / (size - 1));
			array[x][2] += (array[x][2] / (size - 1));
		}
		else
		{
			array[x][0] += (array[x][0] / size);
			array[x][1] += (array[x][1] / size);
			array[x][2] += (array[x][2] / size);
		}
	}
	return (array);
}

int		ft_slv(int **str, int x, int size, char *ptr)
{
	int		i;
	int		printed;
	int		count;

	count = 0;
	while (str[count])
		count++;
	if (x > count - 1)
	{
		ft_putstr(ptr);
		free(ptr);
		while (count >= 0)
		{
			free(str[count]);
			count--;
		}
		exit(1);
		return (1);
	}
	i = -1;
	while (++i < (int)ft_strlen(ptr))
	{
		printed = 0;
		if (ft_isavailable(ptr, i, str[x]))
		{
			ptr = ft_print(ptr, i, str[x], x);
			printed = 1;
			if (ft_slv(str, x + 1, size, ptr))
				return (1);
		}
		if (printed)
			ptr = ft_unprint(ptr, i, str[x]);
	}
	if (x == 0 && (size += 1))
		return (ft_slv(ft_mod(str, size, -1), 0, size, ft_grd(size)));
	return (0);
}

int		main(int argc, char **argv)
{
	char	*read;
	int		check_if_valid;
	int		**identify_tetriminos;
	int		solve;

	if (argc != 2)
		ft_error_usage();
	read = ft_read_input(argv[1]);
	check_if_valid = ft_check_valid(read);
	identify_tetriminos = ft_identify(read, check_if_valid);
	solve = ft_slv(identify_tetriminos, 0, 4, ft_grd(4));
	return (0);
}
