/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumedi <ssumedi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:54:52 by ssumedi           #+#    #+#             */
/*   Updated: 2017/11/20 22:35:26 by ssumedi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

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
