/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 19:22:09 by dmtur             #+#    #+#             */
/*   Updated: 2026/03/23 19:22:21 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	match_var(const char *env_entry, const char *name)
{
	size_t	len;

	len = ft_strlen(name);
	return (ft_strncmp(env_entry, name, len) == 0 && env_entry[len] == '=');
}

static void	remove_var(char *name, char ***env)
{
	int	j;
	int	k;

	j = 0;
	while ((*env)[j])
	{
		if (match_var((*env)[j], name))
		{
			free((*env)[j]);
			k = j;
			while ((*env)[k])
			{
				(*env)[k] = (*env)[k + 1];
				k++;
			}
			j--;
		}
		j++;
	}
}

int	builtin_unset(char **args, char ***env)
{
	int	i;

	if (!args || !args[1])
		return (0);
	i = 1;
	while (args[i])
	{
		remove_var(args[i], env);
		i++;
	}
	return (0);
}
