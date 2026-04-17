/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 11:04:59 by dfrincu           #+#    #+#             */
/*   Updated: 2026/03/03 11:12:02 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _XOPEN_SOURCE 700
#ifndef MINISHELL_H
# define MINISHELL_H

/* ===================== LIBRARIES ===================== */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <signal.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../libft/libft.h"
#include <limits.h> 

/* ===================== GLOBAL ===================== */

extern int	g_signal;

/* ===================== ENUMS ===================== */

typedef enum e_token_type
{
	T_WORD,
	T_PIPE,
	T_REDIR_IN,
	T_REDIR_OUT,
	T_REDIR_APPEND,
	T_HEREDOC
}	t_token_type;

/* ===================== STRUCTS ===================== */

// quote 0: none, '\'': single, '\"': double
typedef struct s_token
{
	char				*value;
	t_token_type		type;
	char				quote;
	struct s_token		*next;
}	t_token;

typedef struct s_redir
{
	t_token_type		type;
	char				*file;
	int					quoted;
	struct s_redir		*next;
}	t_redir;

typedef struct s_cmd
{
	char			**args;
	int				outfile;
	int				infile;
	t_redir			*redirs;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_shell
{
	t_token		*tokens;
	t_cmd		*cmds;
	char		**env;
	int			last_exit;
}	t_shell;

typedef struct s_expand_ctx
{
	char	*result;
	int		j;
}	t_expand_ctx;

typedef struct s_pipe
{
    int	fd[2][2];
    int	in;
    int	out;
    int	last;
    int	out_error;
}	t_pipe;

/* ===================== INIT ===================== */

void	init_shell(t_shell *shell, char **envp);
void	free_shell(t_shell *shell);
int		init_pipeline(t_cmd *cmds);

/* ===================== LOOP ===================== */

void	shell_loop(t_shell *shell);

/* ===================== SIGNALS ===================== */

void	init_signals(void);

/* ===================== LEXER ===================== */

t_token	*lexer(char *input);
int		handle_redir(t_token **tokens, char *input, int i);
int		handle_word(t_token **tokens, char *input, int i);
void	add_token(t_token **list, char *value, t_token_type type, char quote);
void	free_tokens(t_token *tokens);
char	*remove_quotes_and_detect(const char *str, char *quote_type);
int		get_word_end(char *input, int i);
char	get_unclosed_quote(const char *input);
/* ===================== PARSER ===================== */

t_cmd	*parse_tokens(t_token *tokens);
t_cmd	*parse_pipeline(t_token **current);
void	free_cmds(t_cmd *cmds);
void	add_arg(t_cmd *cmd, char *arg);
int		is_redir(t_token_type type);
void	add_redir(t_cmd *cmd, t_token *redir_token, t_token *file_token);
void	print_cmds(t_cmd *cmds);
void	free_redirs(t_redir *redir);
int		check_syntax(t_token *tokens);
int		process_heredocs_and_check_syntax(t_token *tokens);
int	check_redir_syntax_before_heredoc(t_token *tokens, t_token **error_token);

/* ===================== EXECUTOR ===================== */

void	execute(t_shell *shell, t_cmd *cmds);
int		exec_external_command(t_cmd *cmd, char **envp);

/* ===================== BUILTINS ===================== */

int	builtin_cd(char **args, char ***env);
int		builtin_echo(char **args);
int		builtin_env(char **env);
int		builtin_exit(void);
int		builtin_export(char **args, char ***env);
int		builtin_pwd(void);
int		builtin_unset(char **args, char ***env);
int		exec_builtin(t_shell *shell, t_cmd *cmd);
int		is_builtin(char *cmd);
int		match_var(const char *env_entry, const char *name);
void	update_var(char *name, char *value, char ***env);

/* ===================== EXPANSION ===================== */

void	expand_token_list(t_token *tokens, char **env, int last_exit);
char	*expand_vars(const char *input, char **env, int last_exit);

/* ===================== UTILS ===================== */

void	error_exit(char *msg);
void	ft_free_split(char **split);
char	*ft_strjoin_free(char *s1, const char *s2);
void	command_not_found(char *cmd);
void	print_syntax_error(t_token *tokens);
int	line_ends_with_pipe(const char *line);
void	replace_newlines_with_spaces(char *line);
void	expand_vars_in_line(char **line, char **env, int last_exit);
int		line_ends_with_backslash(const char *line);

/* ===================== REDIRECTIONS ===================== */

int	open_infile(const char *file);
int	open_outfile(const char *file, int append);
void	print_redir_error(const char *file, const char *msg);
int	apply_heredoc_redir(t_redir *redir, t_shell *shell, int is_last);
int	apply_redirections(t_cmd *cmd, t_shell *shell);
int	apply_heredoc_token(t_token *heredoc_token, t_shell *shell);

/* ===================== PIPES ===================== */

pid_t	fork_and_exec(t_shell *shell, t_cmd *cmd, t_pipe *pipes);
int		wait_for_children(int n_cmds, pid_t last_pid);
void	init_pipes(t_pipe *pipes);
void	close_pipe(int *fd);
void	duppipe(int *io, int fd);
void	set_fds(t_pipe *pipes, int i, int last);
void	execute_pipeline(t_shell *shell, t_cmd *cmds, int n_cmds);


#endif
