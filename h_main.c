/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahmed <hahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 22:48:43 by hahmed            #+#    #+#             */
/*   Updated: 2017/10/20 19:00:51 by hahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

char	*ft_read(char *input)
{
	int		fd;
	int		ret;
	char	buf[546];
	char	*str;

	fd = open(input, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((ret = read(fd, buf, sizeof(buf))))
	{
		str = ft_strdup(buf);
	}
	close(fd);
	return (str);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%s", ft_read(argv[1]));
	}
	else
	{
		ft_putstr("usage: fillit file\n");
		exit(-1);
	}
	return (0);
}
