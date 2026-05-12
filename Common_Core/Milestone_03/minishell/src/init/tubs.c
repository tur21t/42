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

	ft_bzero(shell, sizeof(*shell));

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
	if (!shell || !shell->env)
		return ;
	while (shell->env[i])
	{
		free(shell->env[i]);
		i++;
	}
	free(shell->env);
	shell->env = NULL;
}

/*void	free_shell(t_shell *shell)
{
    int	i;

    if (!shell)
        return ;

    // libera posibles restos si algún día los guardas en shell
    if (shell->tokens)
        free_tokens(shell->tokens);
    shell->tokens = NULL;

    if (shell->cmds)
        free_cmds(shell->cmds);
    shell->cmds = NULL;

    i = 0;
    if (!shell->env)
        return ;
    while (shell->env[i])
    {
        free(shell->env[i]);
        i++;
    }
    free(shell->env);
    shell->env = NULL;
}*/