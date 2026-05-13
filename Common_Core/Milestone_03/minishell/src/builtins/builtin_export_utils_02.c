/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_utils_02.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 20:07:57 by dmtur             #+#    #+#             */
/*   Updated: 2026/05/12 20:08:05 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_joined_arg(char **args, int *i, char **name, char **value)
{
	char	*joined;
	char	*eq;

	joined = ft_strjoin(args[*i], args[*i + 1]);
	if (!joined)
		return (1);
	eq = ft_strchr(joined, '=');
	*name = ft_substr(joined, 0, eq - joined);
	*value = ft_strdup(eq + 1);
	free(joined);
	*i += 2;
	return (0);
}

void	handle_simple_arg(char *arg, char **name, char **value)
{
	char	*eq;

	eq = ft_strchr(arg, '=');
	*name = ft_substr(arg, 0, eq - arg);
	*value = ft_strdup(eq + 1);
}

void	update_or_add_var(char *name, char *value, char ***env)
{
	int	j;
	int	found;

	found = 0;
	j = 0;
	while ((*env) && (*env)[j])
	{
		if (match_var((*env)[j], name))
		{
			update_var(name, value, env);
			found = 1;
			break ;
		}
		j++;
	}
	if (!found)
		add_var(name, value, env);
}
