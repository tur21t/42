/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 21:29:28 by dmtur             #+#    #+#             */
/*   Updated: 2026/03/23 21:29:50 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*build_env_entry(char *name, char *value)
{
	char	*new_entry;
	size_t	name_len;
	size_t	value_len;

	name_len = ft_strlen(name);
	value_len = ft_strlen(value);
	new_entry = malloc(name_len + value_len + 2);
	if (new_entry)
	{
		ft_strlcpy(new_entry, name, name_len + 1);
		new_entry[name_len] = '=';
		ft_strlcpy(new_entry + name_len + 1, value, value_len + 1);
	}
	return (new_entry);
}

static void	copy_env(char **dst, char **src, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		dst[i] = src[i];
		i++;
	}
}

static void	add_var(char *name, char *value, char ***env)
{
	int		count;
	int		i;
	char	**new_env;
	char	*new_entry;

	count = 0;
	i = 0;
	while ((*env)[count])
		count++;
	new_env = malloc(sizeof(char *) * (count + 2));
	if (!new_env)
		return ;
	copy_env(new_env, *env, count);
	i = count;
	new_entry = build_env_entry(name, value);
	if (new_entry)
	{
		new_env[i] = new_entry;
		i++;
	}
	new_env[i] = NULL;
	free(*env);
	*env = new_env;
}

int	builtin_export(char **args, char ***env)
{
	int		i;
	char	*eq;
	char	*name;
	char	*value;

	i = 1;
	while (args[i])
	{
		eq = ft_strchr(args[i], '=');
		if (eq)
		{
			name = ft_substr(args[i], 0, eq - args[i]);
			value = ft_strdup(eq + 1);
			if (name && value)
			{
				update_var(name, value, env);
				add_var(name, value, env);
			}
			free(name);
			free(value);
		}
		i++;
	}
	return (0);
}
