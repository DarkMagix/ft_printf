#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mweir <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/18 15:36:24 by mweir             #+#    #+#              #
#    Updated: 2018/06/08 17:30:04 by mweir            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FLAGS = -g -Wall -Wextra -Werror -I libft

NAME = libftprintf.a

TRASH = rm -f

LIBFT := libft/

SRC = args.c formatting.c helper.c output.c \
		format_int.c ft_printf.c parse.c output2.c


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT)
	@ar rc $(NAME) $(OBJ) libft/*.o
	@ranlib $(NAME) libft/libft.a

clean:
	$(TRASH) $(OBJ)
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	$(TRASH) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all
