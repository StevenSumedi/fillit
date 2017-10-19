/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumedi <ssumedi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 15:49:49 by ssumedi           #+#    #+#             */
/*   Updated: 2017/10/18 18:09:40 by ssumedi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>



char	check_for_valid_shape()
{
	
}

char	check_for_valid_tetrimino()
{
	count each '#' and each '.';
	conditions:
		sum = 16
		OR
		12 '.' and 4 '#';
	if conditions not met:
		error OR (0);
	if conditions met:
		check for a '\n' and run again
			else return (1) and proceed. 
}

int		main()
{
	check_for_valid_tetrimino()
}
