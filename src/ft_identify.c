/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_identify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumedi <ssumedi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:57:07 by ssumedi           #+#    #+#             */
/*   Updated: 2017/11/20 19:58:15 by ssumedi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../include/fillit.h"

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
