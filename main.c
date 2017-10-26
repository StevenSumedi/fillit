/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumedi <ssumedi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:39:34 by ssumedi           #+#    #+#             */
/*   Updated: 2017/10/26 14:05:45 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "fillit.h"

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

void	ft_error_usage(void)
{
	ft_putstr("usage: fillit [sfdsf]\n");
	exit(0);
}

int		ft_check_valid(char *str)
{
	int		i;
	int		pound;
	int		period;
	int		line;

	i = 0;
	pound = 0;
	period = 0;
	line = 0;
	while (str[i])
	{
		if (str[i] == '#')
			pound++;
		else if (str[i] == '.')
			period++;
		else if (str[i] == '\n')
			line++;
		else
			ft_error();
		i++;
	}
	if (((pound % 4) != 0) || (pound < 4) || (period % 12) != 0)
		ft_error();
	return (pound / 4);
}

char	*ft_read_input(char *input)
{
	int		i;
	int		fd;
	int		make_buffer;
	char	temp[545];
	char	buffer[1];

	i = 0;
	make_buffer = 0;
	fd = open(input, O_RDONLY);
	if (fd == -1)
		ft_error();
	while ((make_buffer = read(fd, buffer, 1)))
	{
		temp[i] = buffer[0];
		if (i > 545)
			ft_error();
		i++;
	}
	temp[i] = '\0';
	if (close(fd) == -1)
		ft_error();
	return(ft_strdup(temp));
}

int		*ft_isshape(char *str, int i, int a, int b, int c)
{
	static int	array[3];

	if (str[i + a] == '#' && str[i + b] == '#' && str[i + c] == '#')
	{
		array[0] = a;
		array[1] = b;
		array[2] = c;
		return (array);
	}
	return (0);
}

int		*ft_tetrimino(char *str, int i)
{
	if (ft_isshape(str, i, 1, 5, 6))
		return (ft_isshape(str, i, 1, 5, 6));
	if (ft_isshape(str, i, 5, 9, 10))
		return (ft_isshape(str, i, 5, 9, 10));
	if (ft_isshape(str, i, 5, 6, 7))
		return (ft_isshape(str, i, 5, 6, 7));
	if (ft_isshape(str, i, 1, 5, 10))
		return (ft_isshape(str, i, 1, 5, 10));
	if (ft_isshape(str, i, 1, 2, 7))
		return (ft_isshape(str, i, 1, 2, 7));
	if (ft_isshape(str, i, 5, 10, 11))
		return (ft_isshape(str, i, 5, 10, 11));
	if (ft_isshape(str, i, 1, 2, 5))
		return (ft_isshape(str, i, 5, 10, 11));
	if (ft_isshape(str, i, 1, 6, 11))
		return (ft_isshape(str, i, 1, 6, 11));
	if (ft_isshape(str, i, 3, 4, 5))
		return (ft_isshape(str, i, 3, 4, 5));
	if (ft_isshape(str, i, 1, 6, 7))
		return (ft_isshape(str, i, 1, 6, 7));
	if (ft_isshape(str, i, 4, 5, 9))
		return (ft_isshape(str, i, 4, 5, 9));
	if (ft_isshape(str, i, 1, 4, 5))
		return (ft_isshape(str, i, 1, 4, 5));
	if (ft_isshape(str, i, 5, 6, 11))
		return (ft_isshape(str, i, 5, 6, 11));
	if (ft_isshape(str, i, 1, 2, 3))
		return (ft_isshape(str, i, 1, 2, 3));
	if (ft_isshape(str, i, 5, 10, 15))
		return (ft_isshape(str, i, 5, 10, 15));
	if (ft_isshape(str, i, 4, 5, 6))
		return (ft_isshape(str, i, 4, 5, 6));
	if (ft_isshape(str, i, 5, 6, 10))
		return (ft_isshape(str, i, 5, 6, 10));
	if (ft_isshape(str, i, 1, 2, 6))
		return (ft_isshape(str, i, 1, 2, 6));
	if (ft_isshape(str, i, 4, 5, 10))
		return (ft_isshape(str, i, 4, 5, 10));
	return (0);
}

int		**ft_identify(char *str, int count)
{
	int		i;
	int		j;
	int		**tetriminos;

	tetriminos = (int**)malloc(sizeof(int*) * count);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			if (ft_tetrimino(str, i) != 0)
			{
				tetriminos[j] = ft_tetrimino(str, i);
				j++;
				i = (j * 21) - 1;
			}
			else
				return (0);
		}
		i++;
	}
	i = 0;
	j = 0;
	while (i < 3)
	{
		while (j < 3)
		{
			printf("%d\n", tetriminos[i][j]);
			j++;
		}
		j = 0;
		i++;
	}	
	return (tetriminos);
}

char	*ft_grid(int size)
{
	int		i;
	int		j;
	char	*output;

	i = 0;
	j = 0;
	output = (char*)malloc(sizeof(char) * ((size * (size + 1)) + 1));
	while ((i < ((size * (size + 1)))))
	{
		while (j < size)
		{
			output[i] = '.';
			i++;
			j++;
		}
		output[i] = '\n';
		j = 0;
		i++;
	}
	output[i] = '\0';
	return (output);
}

int		main(int argc, char **argv)
{
	char	*READ;
	int		CHECK_IF_VALID;
	int		*IDENTIFY_TETRIMINOS;

	if (argc != 2)
		ft_error_usage();
	READ = ft_read_input(argv[1]);
	CHECK_IF_VALID = ft_check_valid(READ);
	IDENTIFY_TETRIMINOS = *ft_identify(READ, CHECK_IF_VALID);
	return (0);
}
