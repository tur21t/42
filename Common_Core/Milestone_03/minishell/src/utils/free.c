/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 14:06:32 by dfrincu           #+#    #+#             */
/*   Updated: 2026/03/22 14:06:33 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

char	*ft_strjoin_free(char *s1, const char *s2)
{
	char	*joined;
	
	joined = ft_strjoin(s1, s2);
	free(s1);
	return (joined);
}

void	cleanup_shell(t_shell *shell, int clear_rl_history)
{
    if (shell)
        free_shell(shell);
    if (clear_rl_history)
    {
        rl_clear_history();
        clear_history();
    }
}

void	free_envp(char **env)
{
    int	i;

    if (!env)
        return;
    i = 0;
    while (env[i])
    {
        free(env[i]);
        i++;
    }
    free(env);
}
