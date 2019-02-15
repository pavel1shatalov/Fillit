# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggerhold <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/23 16:57:48 by ggerhold          #+#    #+#              #
#    Updated: 2019/02/15 18:21:34 by ggerhold         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit 

CC = gcc

FLAGS = -Wall -Wextra -Werror

SRC = *.c

OBJ = *.o

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	$(CC) $(FLAGS) -c $(SRC)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ) -L libft/ -lft

clean:
	rm -rf $(OBJ)
	make -C libft/ clean

fclean: clean
	rm -rf $(NAME)
	make -C libft/ fclean

re: fclean all
