/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumedi <ssumedi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:58:45 by ssumedi           #+#    #+#             */
/*   Updated: 2017/11/20 19:59:27 by ssumedi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../include/fillit.h"

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
