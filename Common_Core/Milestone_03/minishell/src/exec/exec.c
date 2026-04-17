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

void execute(t_shell *shell, t_cmd *cmds)
{
	if (!cmds || !cmds->args || !cmds->args[0])
	{
		shell->last_exit = 0;
		return;
	}
	if (is_builtin(cmds->args[0]))
	{
		int ret = exec_builtin(shell, cmds);
		shell->last_exit = ret;
	}
	else
	{
		int status = exec_external_command(cmds, shell->env);
		if (WIFEXITED(status))
			shell->last_exit = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			shell->last_exit = 128 + WTERMSIG(status);
		else
			shell->last_exit = 1;
	}
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