/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumedi <ssumedi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:25:31 by ssumedi           #+#    #+#             */
/*   Updated: 2017/10/31 19:15:21 by ssumedi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void	ft_error(void);
void	ft_error_usage(void);
int		ft_check_valid(char *str);
char	*ft_read_input(char *input);
int		ft_isshape(int *array, int a, int b, int c);
int		ft_tetrimino_check(int *array);
int		ft_tetrimino_check_two(int *array);
int		*ft_tetrimino(char *str, int i);
int		**ft_identify(char *str, int count);
char	*ft_grid(int size);
int		ft_isavailable(char *str, int i, int *array);
char	*ft_print(char *str, int i, int *array, int count);
char	*ft_unprint(char *str, int i, int *array);
int		**ft_modify(int **array, int size);
int		ft_solve(int **str, int x, int size, char *ptr);

#endif
