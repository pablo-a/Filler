# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabril <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/17 17:57:22 by pabril            #+#    #+#              #
#    Updated: 2016/03/19 12:25:58 by pabril           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

FILE = main.c \
	   lecture.c \
	   resolution.c \
	   test.c

SRCS = $(addprefix src/, $(FILE))
INC = -I includes -I libft -I ft_printf

CC = gcc
FLAGS = -Wall -Wextra
LIB = libft/libft.a
PRINTF = ft_printf/libftprintf.a

all : $(NAME)

$(NAME) :
	@make -C libft
	@make -C ft_printf
	@echo "building filler binary"
	$(CC) $(FLAGS) -o $(NAME) $(INC) $(SRCS) $(LIB) $(PRINTF)

clean :
	@echo "delete *.o in filler"
	@rm -f *.o 

fclean_lib :
	@make fclean -C libft

fclean_printf :
	@make fclean -C ft_printf

fclean : fclean_lib fclean_printf clean
	@echo "removing $(NAME) binary"
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
