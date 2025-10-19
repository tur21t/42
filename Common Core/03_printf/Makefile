# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmtur <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 15:31:23 by dmtur             #+#    #+#              #
#    Updated: 2025/10/15 15:37:29 by dmtur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC	=	ft_printf.c 		\
		ft_putchar_pf.c		\
	       	ft_putstr_pf.c		\
	       	ft_putnbr_pf.c		\
		ft_put_unsigned_pf.c	\
		ft_put_hex_pf.c		\
		ft_put_ptr_pf.c		\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
