# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nirvine <nirvine@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 17:53:35 by nirvine           #+#    #+#              #
#    Updated: 2024/08/25 16:59:12 by nirvine          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c\
	  ft_ptr_hex.c\
	  ft_put_unsigned.c\
	  ft_putchar.c\
	  ft_puthex.c\
	  ft_putnbr.c\
	  ft_putstr.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
