NAME        = minishell
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -Iinc
RM = rm -f

LIBFT_DIR	= ./libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

SRCS        = src/core/main.c src/core/loop.c \
			  src/signals/signals.c \
			  src/lexer/lexer.c src/lexer/lexer_support.c \
			  src/init/tubs.c \
			  src/parser/parser.c src/parser/parser_support.c src/parser/parser_support02.c \
			  src/exec/exec.c src/exec/exec_external_commands.c \
			  src/utils/free.c \
			  src/builtins/exec_builtin.c src/builtins/builtin_cd.c src/builtins/echo.c src/builtins/builtin_env.c src/builtins/exit.c src/builtins/builtin_export.c src/builtins/builtin_export_utils.c src/builtins/pwd.c src/builtins/builtin_unset.c\
			  #src/redirections/ \
			  #src/expansion \

OBJS        = $(SRCS:.c=.o)

all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_A) Makefile inc/minishell.h
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -lreadline -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	$(RM) $(OBJS)
	$(RM) $(SRCS:.c=.d)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

-include $(SRCS:.c=.d)

