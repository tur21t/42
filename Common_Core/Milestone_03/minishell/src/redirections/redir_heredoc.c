/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 10:36:24 by dfrincu           #+#    #+#             */
/*   Updated: 2026/04/09 10:36:27 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	heredoc_write(
	const char *delimiter, int write_fd, int quoted, char **env)
{
	char	*line;
	int		eof;

	eof = 0;
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			eof = 1;
			break ;
		}
		if (strcmp(line, delimiter) == 0)
			break ;
		if (!quoted)
			expand_vars_in_line(&line, env);
		write(write_fd, line, strlen(line));
		write(write_fd, "\n", 1);
		free(line);
	}
	if (eof)
		printf("minishell: warning: here-document delimited "
			"by end-of-file (wanted `%s')\n", delimiter);
	free(line);
	return (0);
}

int	apply_heredoc_redir(t_redir *redir, t_shell *shell, int is_last)
{
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		return (-1);
	if (heredoc_write(redir->file, pipefd[1], redir->quoted, shell->env) == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return (-1);
	}
	close(pipefd[1]);
	if (is_last)
		dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	return (0);
}

int	apply_heredoc_token(t_token *heredoc_token, t_shell *shell)
{
	char	*delimiter = heredoc_token->next->value;
	int		quote = heredoc_token->next->quote;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		return (-1);
	if (heredoc_write(delimiter, pipefd[1], quote == 0, shell->env) == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return (-1);
	}
	close(pipefd[1]);
	close(pipefd[0]);
	return (0);
}
