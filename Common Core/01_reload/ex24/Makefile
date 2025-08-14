# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmtur <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 21:58:48 by dmtur             #+#    #+#              #
#    Updated: 2025/05/12 21:59:10 by dmtur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_DIR = srcs
INC_DIR = includes

SRC = $(SRC_DIR)/ft_putchar.c \
      $(SRC_DIR)/ft_putstr.c \
      $(SRC_DIR)/ft_strcmp.c \
      $(SRC_DIR)/ft_strlen.c \
      $(SRC_DIR)/ft_swap.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
