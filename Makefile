# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssumedi <ssumedi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/17 14:15:27 by ssumedi           #+#    #+#              #
#    Updated: 2017/10/21 01:35:43 by ssumedi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

CGLAGS = -Wall -Werror -Wextra

RM = rm -rf

SRC = 

OBJ = $(SRC:.c=.o)

$(NAME):
		fillit.h
		$(CC) $(CFLAGS) -c $(SRC)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

all: $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all
