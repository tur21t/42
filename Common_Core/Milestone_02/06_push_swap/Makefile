# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmtur <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/13 00:07:53 by dmtur             #+#    #+#              #
#    Updated: 2025/12/13 00:08:04 by dmtur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Colors
RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
NEON_GREEN = \033[92m

# compilation and flags
CC = cc
INCLUDES = -I. -Ilibft
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = \
	main.c \
	parse/parse_args.c \
	parse/split_args.c \
	parse/validate_numbers.c \
	stack/stack_init.c \
	stack/stack_node.c \
	stack/stack_utils.c \
	stack/stack_free.c \
	operations/operation_swap.c \
	operations/operation_push.c \
	operations/operation_rotate.c \
	operations/operation_rev_rotate.c \
	sort/sort_small.c \
	sort/sort_big.c \
	sort/indexing.c \
	sort/sort_dispatcher.c \
	utils/is_sorted.c \
	utils/errors.c

OBJS = $(SRCS:.c=.o)

# rules


all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(NEON_GREEN)✓ Executable $(NAME) created.$(RESET)"

$(LIBFT):
	@echo "$(GREEN)Building LIBFT...$(RESET)"
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)✓ Libft DONE!$(RESET)"

%.o: %.c push_swap.h libft/libft.h Makefile
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CYAN)	Compiled: $<$(RESET)"

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@echo "$(MAGENTA)Object files of PUSH_SWAP removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(MAGENTA)Executable $(NAME) removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re
