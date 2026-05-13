/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:54:40 by dmtur             #+#    #+#             */
/*   Updated: 2026/05/13 12:54:51 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	has_in_redir(t_redir *r)
{
	while (r)
	{
		if (r->type == T_REDIR_IN || r->type == T_HEREDOC)
			return (1);
		r = r->next;
	}
	return (0);
}

int	has_out_redir(t_redir *r)
{
	while (r)
	{
		if (r->type == T_REDIR_OUT || r->type == T_REDIR_APPEND)
			return (1);
		r = r->next;
	}
	return (0);
}

void	handle_child_status(int status, int *printed_sigint)
{
	if (WIFEXITED(status))
		g_signal = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		if (!*printed_sigint && WTERMSIG(status) == SIGINT)
		{
			write(1, "\n", 1);
			*printed_sigint = 1;
		}
		g_signal = 128 + WTERMSIG(status);
	}
}
