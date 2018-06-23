#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mweir <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/18 15:36:24 by mweir             #+#    #+#              #
#    Updated: 2018/06/16 16:04:11 by mweir            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS = -g -Wall -Wextra -Werror -I libft

NAME = libftprintf.a

TRASH = rm -f

LIBFT := libft/

SRC = args.c print_help.c helper.c output.c \
		ft_printf.c parse.c output2.c \
		lengths.c 
SRC2 = handles/handle_int.c \
		handles/handle_uint.c handles/handle_hex.c handles/handle_octal.c handles/handle_wstring.c \
		handles/handle_ptrs.c handles/handle_string.c main.c


OBJ = $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)


all: $(NAME)

$(NAME): $(OBJ) $(OBJ2)
	@$(MAKE) -C $(LIBFT)
	@ar rc $(NAME) $(OBJ) $(OBJ2) libft/*.o
	@ranlib $(NAME) libft/libft.a

clean:
	$(TRASH) $(OBJ)
	$(TRASH) $(OBJ2)
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	$(TRASH) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all
