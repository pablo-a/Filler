# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabril <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/17 17:57:22 by pabril            #+#    #+#              #
#    Updated: 2016/03/17 18:09:45 by pabril           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

FILE = main.c
SRCS = $(addprefix src/, $(FILES))
INC = -I includes -I libft

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIB = -L libft -lft

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@echo "building filler binary"
	@$(CC) $(FLAGS) -o $(NAME) $(INC) $(LIB)

clean :
	@echo "destroying all objects"
	@rm *.o
	@rm libft/*.o

fclean : clean
	@echo "removing $(NAME)"
	@rm $(NAME)

re : fclean all

.PHONY : all clean fclean re
