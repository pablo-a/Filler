# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabril <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/17 17:57:22 by pabril            #+#    #+#              #
#    Updated: 2016/03/18 18:26:44 by pabril           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

FILE = main.c \
	   lecture.c \
	   resolution.c

SRCS = $(addprefix src/, $(FILE))
INC = -I includes -I libft

CC = gcc
FLAGS = -Wall -Wextra #-Werror
LIB = libft/libft.a

all : $(NAME)

$(NAME) :
	@make -C libft
	@echo "building filler binary"
	$(CC) $(FLAGS) -o $(NAME) $(INC) $(SRCS) $(LIB)

clean :
	@echo "delete *.o in filler"
	@rm -f *.o 

fclean_lib :
	@make fclean -C libft

fclean : clean fclean_lib
	@echo "removing $(NAME) binary"
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
