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
		dst[i] = ft_strdup(src[i]);
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
	free_envp(*env);
	*env = new_env;
}

int	builtin_export(char **args, char ***env)
{
    int		i;
    int		j;
    int		found;
    char	*eq;
    char	*name;
    char	*value;
    char	*joined;

    i = 1;
    while (args[i])
    {
        joined = NULL;
        name = NULL;
        value = NULL;
        eq = ft_strchr(args[i], '=');
        if (eq && eq[1] == '\0' && args[i + 1])
        {
            joined = ft_strjoin(args[i], args[i + 1]);
            if (!joined)
                return (1);
            eq = ft_strchr(joined, '=');
            name = ft_substr(joined, 0, eq - joined);
            value = ft_strdup(eq + 1);
            free(joined);
            i += 2;
        }
        else if (eq)
        {
            name = ft_substr(args[i], 0, eq - args[i]);
            value = ft_strdup(eq + 1);
            i++;
        }
        else
        {
            i++;
            continue ;
        }
        if (name && value)
        {
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
        free(name);
        free(value);
    }
    return (0);
}