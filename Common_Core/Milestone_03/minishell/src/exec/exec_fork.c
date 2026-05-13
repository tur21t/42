/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:28:05 by dfrincu           #+#    #+#             */
/*   Updated: 2026/03/31 15:28:11 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	child_exec(t_shell *shell, t_cmd *cmd, t_pipe *pipes)
{
	int	ret;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (!has_in_redir(cmd->redirs))
	{
		if (dup2(pipes->in, STDIN_FILENO) == -1)
			exit(1);
	}
	if (!has_out_redir(cmd->redirs))
	{
		if (dup2(pipes->out, STDOUT_FILENO) == -1)
			exit(1);
	}
	close_pipe(pipes->fd[0]);
	close_pipe(pipes->fd[1]);
	if (apply_redirections(cmd, shell) == -1)
		exit(1);
	if (is_builtin(cmd->args[0]))
		ret = exec_builtin(shell, cmd);
	else
		ret = exec_external_command(cmd, shell->env);
	free_shell(shell);
	exit(ret);
}

void	fork_and_exec(t_shell *shell, t_cmd *cmd, t_pipe *pipes)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
		child_exec(shell, cmd, pipes);
}

void	wait_for_children(int n_cmds)
{
	int		status;
	int		i;
	pid_t	pid;
	int		printed_sigint;

	i = 0;
	printed_sigint = 0;
	while (i < n_cmds)
	{
		pid = wait(&status);
		if (pid == -1)
		{
			if (errno == EINTR)
				continue ;
			break ;
		}
		handle_child_status(status, &printed_sigint);
		i++;
	}
	if (g_signal == 129)
		g_signal = 130;
}
