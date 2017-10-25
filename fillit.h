/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumedi <ssumedi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 23:33:04 by ssumedi           #+#    #+#             */
/*   Updated: 2017/10/21 01:34:43 by ssumedi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		main(int argc, char **argv);
int		*open_file(int fd);
int		check_map(char *buf);
int		check_count(int period_counter, int pound_counter, int j);
int		check_if_touching(char *buf);

#endif

