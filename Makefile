#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssumedi <ssumedi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/17 14:15:27 by ssumedi           #+#    #+#              #
#    Updated: 2017/11/24 02:52:39 by ssumedi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

SRC = ft_error.c		\
	  ft_read_input.c	\
	  ft_check_input.c	\
	  ft_identify.c		\
	  ft_grid.c			\
	  ft_solve.c		\
	  libft.c		\
	  main.c			\

OBJ = $(SRC:.c=.o)

SRC_PATH = src/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

INC = -I include/

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -g
		
$(OBJ):
		$(CC) $(CFLAGS) -c $(SRC_POS)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
