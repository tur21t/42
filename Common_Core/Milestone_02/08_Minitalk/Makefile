# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmtur <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 14:49:40 by dmtur             #+#    #+#              #
#    Updated: 2025/11/19 20:53:44 by dmtur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable names
SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
LIBFT_DIR = libft
PRINTF_DIR = printf

INCLUDES = -I$(LIBFT_DIR) -I$(PRINTF_DIR)

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a

# Source files
PRINTF_SRC = printf/ft_printf.c printf/ft_putchar_pf.c printf/ft_put_hex_pf.c printf/ft_putnbr_pf.c printf/ft_put_ptr_pf.c printf/ft_putstr_pf.c printf/ft_put_unsigned_pf.c

SERVER_SRC = server.c
CLIENT_SRC = client.c client_utils.c $(PRINTF_SRC)

SERVER_BONUS_SRC = server_bonus.c
CLIENT_BONUS_SRC = client_bonus.c client_utils_bonus.c $(PRINTF_SRC)

# Default compilation
all: $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(SERVER): $(SERVER_SRC) $(LIBFT) $(PRINTF_SRC)
	$(CC) $(CFLAGS) $(SERVER_SRC) $(PRINTF_SRC) $(LIBFT) $(INCLUDES) -o $(SERVER)

$(CLIENT): $(CLIENT_SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_SRC) $(LIBFT) $(INCLUDES) -o $(CLIENT)

# bonus rule
bonus: $(LIBFT) $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(SERVER_BONUS_SRC) $(LIBFT) $(PRINTF_SRC)
	$(CC) $(CFLAGS) $(SERVER_BONUS_SRC) $(PRINTF_SRC) $(LIBFT) $(INCLUDES) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(CLIENT_BONUS_SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_SRC) $(LIBFT) $(INCLUDES) -o $(CLIENT_BONUS)


# Clean rules
clean:
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean re fclean bonus

