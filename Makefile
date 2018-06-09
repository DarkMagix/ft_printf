#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mweir <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/18 15:36:24 by mweir             #+#    #+#              #
#    Updated: 2018/06/08 17:18:17 by mweir            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ft_printf
PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = ./libft/includes/

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEAD = ./ft_printf.h

SRC = args.c formatting.c helper.c output.c format_int.c \
	ft_printf.c main.c parse.c


OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))


all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	make -C libft/
	$(CC) $(CFLAGS) -I $(HEAD) -I $(PATH_INC) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) -lm -L libft/ -lft

.PHONY: clean fclean

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
