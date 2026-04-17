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

static int has_in_redir(t_redir *r) {
	while (r) {
		if (r->type == T_REDIR_IN || r->type == T_HEREDOC)
			return 1;
		r = r->next;
	}
	return 0;
}
static int has_out_redir(t_redir *r) {
	while (r) {
		if (r->type == T_REDIR_OUT || r->type == T_REDIR_APPEND)
			return 1;
		r = r->next;
	}
	return 0;
}

pid_t	fork_and_exec(t_shell *shell, t_cmd *cmd, t_pipe *pipes)
{
	pid_t	pid;
	int		code;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (pid == 0)
	{
		if (!has_in_redir(cmd->redirs))
			if (dup2(pipes->in, STDIN_FILENO) == -1)
				exit(1);
		if (!has_out_redir(cmd->redirs))
			if (dup2(pipes->out, STDOUT_FILENO) == -1)
				exit(1);
		close_pipe(pipes->fd[0]);
		close_pipe(pipes->fd[1]);
		if (apply_redirections(cmd, shell) == -1)
			exit(1);
		if (is_builtin(cmd->args[0]))
			code = exec_builtin(shell, cmd);
		else
			code = exec_external_command(cmd, shell->env);
		exit(code);
	}
	return (pid);
}

int	wait_for_children(int n_cmds, pid_t last_pid)
{
	int		i;
	int		status;
	int		last_status;
	pid_t	pid;

	i = 0;
	last_status = 0;
	while (i < n_cmds)
	{
		pid = wait(&status);
		if (pid == last_pid)
			last_status = status;
		i++;
	}
	if (WIFEXITED(last_status))
		return (WEXITSTATUS(last_status));
	if (WIFSIGNALED(last_status))
		return (128 + WTERMSIG(last_status));
	return (1);
}

// void	fork_and_exec(t_shell *shell, t_cmd *cmd, t_pipe *pipes)
// {
// 	pid_t	pid;

// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("fork");
// 		exit(1);
// 	}
// 	if (pid == 0)
// 	{
// 		if (!has_in_redir(cmd->redirs))
// 		{
// 			if (dup2(pipes->in, STDIN_FILENO) == -1)
// 				exit(1);
// 		}
// 		if (!has_out_redir(cmd->redirs))
// 		{
// 			if (dup2(pipes->out, STDOUT_FILENO) == -1)
// 				exit(1);
// 		}
// 		close_pipe(pipes->fd[0]);
// 		close_pipe(pipes->fd[1]);
// 		if (apply_redirections(cmd, shell) == -1)
// 			exit(1);
// 		if (is_builtin(cmd->args[0]))
// 			exec_builtin(shell, cmd);
// 		else
// 			exec_external_command(cmd, shell->env);
// 		exit(0);
// 	}
// }

// void	wait_for_children(int n_cmds)
// {
// 	int	i;
// 	int	status;

// 	i = 0;
// 	while (i < n_cmds)
// 	{
// 		wait(&status);
// 		i++;
// 	}
// }
