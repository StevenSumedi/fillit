/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumedi <ssumedi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:25:31 by ssumedi           #+#    #+#             */
/*   Updated: 2017/11/24 04:55:29 by ssumedi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void	ft_error(void);
void	ft_usage_message(void);
char	*ft_read_input(char *input);
int		ft_check_input(char *str);
int		ft_compare(int *coords, int a, int b, int c);
int		ft_check_coords(int *coords);
int		*ft_return_coords(char *str, int i);
int		**ft_identify(char *str, int count);
char	*ft_grid(int size);
int		ft_is_available(char *str, int i, int *coords);
char	*ft_print(char *str, int i, int *coords, char c);
int		**ft_scale(int **tetro, int *n, int x);
int		ft_solve(int **tetro, int x, int *n, char *str);
int		**ft_convert(int **tetro, int size, int x, int count);
int		ft_special(int **tetro, int count);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);

#endif
