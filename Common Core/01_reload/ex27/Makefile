# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmtur <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/17 17:23:55 by dmtur             #+#    #+#              #
#    Updated: 2025/05/21 15:03:20 by dmtur            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= ft_display_file
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
SRCS_DIR		= srcs
SRCS			= srcs/main.c srcs/util.c
OBJS_DIR		= $(SRCS_DIR)
OBJS			= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS))
RM				= rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
