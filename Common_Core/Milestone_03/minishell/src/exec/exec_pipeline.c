/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:35:34 by dfrincu           #+#    #+#             */
/*   Updated: 2026/04/15 11:19:45 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_pipes(t_pipe *pipes)
{
    pipes->fd[0][0] = -1;
    pipes->fd[0][1] = -1;
    pipes->fd[1][0] = -1;
    pipes->fd[1][1] = -1;
    pipes->in = STDIN_FILENO;
    pipes->out = STDOUT_FILENO;
    pipes->last = 1;
    pipes->out_error = STDERR_FILENO;
}

void	close_pipe(int *fd)
{
	if (fd[0] >= 0)
		close(fd[0]);
	if (fd[1] >= 0)
		close(fd[1]);
}

void	duppipe(int *io, int fd)
{
	close(*io);
	*io = dup(fd);
}

void	set_fds(t_pipe *pipes, int i, int last)
{
    if (i == 0)
    {
        pipes->in = STDIN_FILENO;
        if (!last)
            pipes->out = pipes->fd[i % 2][1];
        else
            pipes->out = STDOUT_FILENO;
    }
    else
    {
        pipes->in = pipes->fd[(i + 1) % 2][0];
        if (!last)
            pipes->out = pipes->fd[i % 2][1];
        else
            pipes->out = STDOUT_FILENO;
    }
}

void	execute_pipeline(t_shell *shell, t_cmd *cmds, int n_cmds)
{
    t_pipe	pipes;
    t_cmd	*curr;
    int		i;

    init_pipes(&pipes);
    curr = cmds;
    i = 0;
    while (curr)
    {
        if (curr->next)
            pipe(pipes.fd[i % 2]);
        set_fds(&pipes, i, curr->next == NULL);
        fork_and_exec(shell, curr, &pipes);
        if (curr->next)
            close(pipes.fd[i % 2][1]);
        if (i > 0)
            close(pipes.fd[(i + 1) % 2][0]);
        curr = curr->next;
        i++;
    }
    wait_for_children(n_cmds);
}
