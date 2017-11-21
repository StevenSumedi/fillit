# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssumedi <ssumedi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/17 14:15:27 by ssumedi           #+#    #+#              #
#    Updated: 2017/11/20 21:48:08 by hahmed           ###   ########.fr        #
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
	  main.c			\

OBJ = $(SRC:.c=.o)

SRC_PATH = src/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

INC = -I include/

LIBFT = src/libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
		
$(OBJ): $(LIBFT)
		$(CC) $(CFLAGS) -c $(SRC_POS)

$(LIBFT):
		git submodule init ./src/libft/
		git submodule update ./src/libft/
		make -C ./src/libft/

clean:
		$(RM) $(OBJ)
		make clean -C ./src/libft/

fclean: clean
		$(RM) $(NAME)
		make fclean -C ./src/libft/

re: fclean all

.PHONY: all clean fclean re
