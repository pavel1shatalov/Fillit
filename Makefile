# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/23 16:57:48 by ggerhold          #+#    #+#              #
#    Updated: 2019/02/08 19:44:42 by ggerhold         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit 

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = *.c

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -o $(NAME) $(SRC) -L libft/ -lft 

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
