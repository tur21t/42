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
	if (strcmp(cmd->args[0], "pwd") == 0)
		return (builtin_pwd());
	// ... other built-ins
	return (1);
}

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (strcmp(cmd, "pwd") == 0)
		return (1);
	// ... add other built-ins here as you implement them
	return (0);
}
