/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 19:01:19 by dmtur             #+#    #+#             */
/*   Updated: 2026/03/22 19:01:23 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_builtin(t_shell *shell, t_cmd *cmd)
{
	(void)shell;
	if (!cmd || !cmd->args || !cmd->args[0])
		return (1);
	if (ft_strncmp(cmd->args[0], "cd", 3) == 0)
		return (builtin_cd(cmd->args, &(shell->env)));
	if (ft_strncmp(cmd->args[0], "echo", 5) == 0)
	{
		//expand_args(cmd->args, cmd->quotes, shell->env);
		return (builtin_echo(cmd->args));
	}
	if (ft_strncmp(cmd->args[0], "env", 4) == 0)
		return (builtin_env(shell->env));
	if (ft_strncmp(cmd->args[0], "exit", 5) == 0)
		return (builtin_exit(cmd->args));
	if (ft_strncmp(cmd->args[0], "export", 7) == 0)
		return (builtin_export(cmd->args, &(shell->env)));
	if (ft_strncmp(cmd->args[0], "pwd", 4) == 0)
		return (builtin_pwd());
	if (ft_strncmp(cmd->args[0], "unset", 6) == 0)
		return (builtin_unset(cmd->args, &(shell->env)));
	return (1);
}

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (ft_strncmp(cmd, "cd", 3) == 0)
		return (1);
	if (ft_strncmp(cmd, "echo", 5) == 0)
		return (1);
	if (ft_strncmp(cmd, "env", 4) == 0)
		return (1);
	if (ft_strncmp(cmd, "exit", 5) == 0)
		return (1);
	if (ft_strncmp(cmd, "export", 7) == 0)
		return (1);
	if (ft_strncmp(cmd, "pwd", 4) == 0)
		return (1);
	if (ft_strncmp(cmd, "unset", 6) == 0)
		return (1);
	return (0);
}
