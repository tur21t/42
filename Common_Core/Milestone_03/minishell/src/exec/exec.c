/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:21:27 by dfrincu           #+#    #+#             */
/*   Updated: 2026/03/16 13:21:28 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_single_builtin(t_shell *shell, t_cmd *cmd)
{
	int	in;
	int	out;

	in = dup(STDIN_FILENO);
	out = dup(STDOUT_FILENO);
	if (in < 0 || out < 0)
		return ;
	if (apply_redirections(cmd, shell) == -1)
	{
		dup2(in, STDIN_FILENO);
		dup2(out, STDOUT_FILENO);
		close(in);
		close(out);
		return ;
	}
	g_signal = exec_builtin(shell, cmd);
	dup2(in, STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	close(in);
	close(out);
}

void	execute(t_shell *shell, t_cmd *cmds)
{
	int	n_cmds;

	if (!cmds)
		return ;
	n_cmds = init_pipeline(cmds);
	if (n_cmds == 1 && cmds->args && cmds->args[0] && is_builtin(cmds->args[0]))
	{
		exec_single_builtin(shell, cmds);
		return ;
	}
	execute_pipeline(shell, cmds, n_cmds);
}

/*void	execute(t_shell *shell, t_cmd *cmds)
{
	int n_cmds;

	n_cmds = init_pipeline(cmds);
	if (n_cmds == 1)
	{
		if (is_builtin(cmds->args[0]))
			exec_builtin(shell, cmds);
		else
			exec_external_command(cmds, shell->env);
	}
	else
	{
		execute_pipeline(shell, cmds, n_cmds);
	}
}*/