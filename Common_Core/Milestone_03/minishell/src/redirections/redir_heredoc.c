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

static int	heredoc_write(const char *delimiter, int write_fd)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line || strcmp(line, delimiter) == 0)
			break ;
		write(write_fd, line, strlen(line));
		write(write_fd, "\n", 1);
		free(line);
	}
	free(line);
	return (0);
}

int	apply_heredoc_redir(t_redir *redir)
{
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		return (-1);
	if (heredoc_write(redir->file, pipefd[1]) == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return (-1);
	}
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	return (0);
}
