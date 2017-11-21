/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumedi <ssumedi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:55:34 by ssumedi           #+#    #+#             */
/*   Updated: 2017/11/20 19:56:22 by ssumedi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "../include/fillit.h"

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
