/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumedi <ssumedi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:39:34 by ssumedi           #+#    #+#             */
/*   Updated: 2017/11/20 22:36:21 by ssumedi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

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
