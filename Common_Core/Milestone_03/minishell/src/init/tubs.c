/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tubs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 20:00:25 by dmtur             #+#    #+#             */
/*   Updated: 2026/03/23 20:00:34 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_shell(t_shell *shell, char **envp)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (envp[count])
		count++;
	shell->env = malloc(sizeof(char *) * (count + 1));
	if (!shell->env)
		return ;
	while (i < count)
	{
		shell->env[i] = ft_strdup(envp[i]);
		i++;
	}
	shell->env[count] = NULL;
	// Luego inicializar mas cosas
}

void	free_shell(t_shell *shell)
{
	int	i;

	i = 0;
	if (!shell->env)
		return ;
	while (shell->env[i])
	{
		free(shell->env[i]);
		i++;
	}
	free(shell->env);
}
