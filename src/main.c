/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumedi <ssumedi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:39:34 by ssumedi           #+#    #+#             */
/*   Updated: 2017/11/24 21:35:22 by ssumedi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		ft_special(int **tetro, int count)
{
	int		x;

	x = 0;
	while (tetro[x] && x < count)
	{
		if ((tetro[x][0] == 1 && tetro[x][1] == 2 && tetro[x][2] == 3) ||
				(tetro[x][0] == 5 && tetro[x][1] == 10 && tetro[x][2] == 15))
			return (1);
		x++;
	}
	return (0);
}

int		ft_2x2(int **tetro, int count)
{
	int		x;

	x = 0;
	while (tetro[x] && x < count)
	{
		if (tetro[x][0] == 1 && tetro[x][1] == 5 && tetro[x][2] == 6)
			return (1);
		x++;
	}
	return (0);
}

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
		n[0] = 3;
		n[1] = check_input;
		if (ft_2x2(identify_tetriminos, check_input) && check_input == 1)
		{
			ft_putstr("AA\nAA\n");
			exit(1);
		}
		if (ft_special(identify_tetriminos, check_input))
			n[0] = 4;
		solve = ft_solve(identify_tetriminos, 0, n, ft_grid(n[0]));
	}
	ft_usage_message();
	return (0);
}
