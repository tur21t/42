/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 21:05:40 by dmtur             #+#    #+#             */
/*   Updated: 2026/03/22 21:05:49 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_numeric(const char *s)
{
	int	i;

	i = 0;
	if (!s || !s[0])
		return (0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!ft_isdigit(s[i]))
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

int	builtin_exit(t_shell *shell, char **args)
{
	write(1, "exit\n", 5);
	if (!shell)
		return (1);
	if (args && args[1] && args[2])
	{
		write(2, "minishell: exit: too many arguments\n", 36);
		shell->last_exit = 1;
		return (1);
	}
	shell->should_exit = 1;
	if (!args || !args[1])
	{
		shell->last_exit = g_signal;
		return (shell->last_exit);
	}
	if (!is_numeric(args[1]))
	{
		write(2, "minishell: exit: ", 17);
		write(2, args[1], ft_strlen(args[1]));
		write(2, ": numeric argument required\n", 28);
		shell->last_exit = 2;
		return (shell->last_exit);
	}
	shell->last_exit = (unsigned char)ft_atoi(args[1]);
	return (shell->last_exit);
}
