/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 09:39:21 by dfrincu           #+#    #+#             */
/*   Updated: 2026/04/09 09:39:23 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static int	apply_in_redir(t_redir *redir)
{
	int	fd;

	fd = open_infile(redir->file);
	if (fd == -1)
		return (-1);
	if (dup2(fd, STDIN_FILENO) == -1)
		perror("dup2 in");
	close(fd);
	return (0);
}

static int	apply_out_redir(t_redir *redir, int append)
{
	int	fd;

	fd = open_outfile(redir->file, append);
	if (fd == -1)
		return (-1);
	if (dup2(fd, STDOUT_FILENO) == -1)
		perror("dup2 out");
	close(fd);
	return (0);
}

static int	apply_one_redir(t_redir *redir)
{
	if (redir->type == T_REDIR_IN)
		return (apply_in_redir(redir));
	else if (redir->type == T_REDIR_OUT)
		return (apply_out_redir(redir, 0));
	else if (redir->type == T_REDIR_APPEND)
		return (apply_out_redir(redir, 1));
	//else if (redir->type == T_HEREDOC)
	//	return (apply_heredoc_redir(redir, shell));
	return (0);
}

static int	count_heredocs(t_redir *redir)
{
    int count = 0;
    while (redir)
    {
        if (redir->type == T_HEREDOC)
            count++;
        redir = redir->next;
    }
    return count;
}

int	apply_redirections(t_cmd *cmd, t_shell *shell)
{
	t_redir	*redir;
	int		hindex;
	int		hcount;

	hcount = count_heredocs(cmd->redirs);
	hindex = 0;
	redir = cmd->redirs;
	while (redir)
	{
		if (redir->type == T_HEREDOC)
		{
			hindex++;
			if (apply_heredoc_redir(redir, shell, hindex == hcount) == -1)
				return (-1);
		}
		else if (apply_one_redir(redir) == -1)
			return (-1);
		redir = redir->next;
	}
	return (0);
}
