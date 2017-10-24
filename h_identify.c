/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 19:11:18 by hahmed            #+#    #+#             */
/*   Updated: 2017/10/23 18:32:07 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

int		ft_isshape(char *str, int i, int a, int b, int c)
{
	if (str[i + a] == '#' && str[i + b] == '#' && str[i + c] == '#')
		return (1);
	return (0);
}

int		ft_identify(char *str, int i)
{
	if (ft_isshape(str, i, 1, 5, 6))
		return (1);
	if (ft_isshape(str, i, 5, 9, 10))
		return (2);
	if (ft_isshape(str, i, 5, 6, 7))
		return (3);
	if (ft_isshape(str, i, 1, 5, 10))
		return (4);
	if (ft_isshape(str, i, 1, 2, 7))
		return (5);
	if (ft_isshape(str, i, 5, 10, 11))
		return (6);
	if (ft_isshape(str, i, 1, 2, 5))
		return (7);
	if (ft_isshape(str, i, 1, 6, 11))
		return (8);
	if (ft_isshape(str, i, 3, 4, 5))
		return (9);
	if (ft_isshape(str, i, 1, 6, 7))
		return (10);
	if (ft_isshape(str, i, 4, 5, 9))
		return (11);
	if (ft_isshape(str, i, 1, 4, 5))
		return (12);
	if (ft_isshape(str, i, 5, 6, 11))
		return (13);
	if (ft_isshape(str, i, 1, 2, 3))
		return (14);
	if (ft_isshape(str, i, 5, 10, 15))
		return (15);
	if (ft_isshape(str, i, 4, 5, 6))
		return (16);
	if (ft_isshape(str, i, 5, 6, 10))
		return (17);
	if (ft_isshape(str, i, 1, 2, 6))
		return (18);
	if (ft_isshape(str, i, 4, 5, 10))
		return (19);
	return (0);
}

int		*ft_something(char *str)
{
	int	*tetriminos;
	int	count;
	int i;

	tetriminos = (int *)malloc(sizeof(int) * ((ft_strlen(str) + 1) / 21));
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (ft_identify(str, i) > 0)
			{
				*tetriminos = ft_identify(str, i);
				tetriminos++;
				count++;
				i = (count * 21) - 1;
			}
			else
				return (0);
		}
		i++;
	}
	return (tetriminos);
}

void	ft_putnbrarray(int *nbr)
{
	while (*nbr)
	{
		ft_putnbr(*nbr);
		nbr++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_putnbrarray(ft_something(argv[1]));
	return (0);
}
