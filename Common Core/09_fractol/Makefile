# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmtur <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/09 19:16:46 by dmtur             #+#    #+#              #
#    Updated: 2026/01/11 14:11:52 by dmtur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)
MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx.a -lXext -lX11

INCLUDES = -I.

SRC =	main.c \
		events.c \
		render.c \
		render_julia.c \
		parse.c \
		utils/ft_atof.c \
		utils/ft_isfloat.c \
		utils/ft_strlen.c \
		utils/ft_strcmp.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): Makefile $(OBJ) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)
	
$(MLX_DIR)/libmlx.a:
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all FORCE clean fclean re
