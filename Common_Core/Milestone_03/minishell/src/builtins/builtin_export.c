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
//moved to utils.c
// static char	*build_env_entry(char *name, char *value)
// {
// 	char	*new_entry;
// 	size_t	name_len;
// 	size_t	value_len;

// 	name_len = ft_strlen(name);
// 	value_len = ft_strlen(value);
// 	new_entry = malloc(name_len + value_len + 2);
// 	if (new_entry)
// 	{
// 		ft_strlcpy(new_entry, name, name_len + 1);
// 		new_entry[name_len] = '=';
// 		ft_strlcpy(new_entry + name_len + 1, value, value_len + 1);
// 	}
// 	return (new_entry);
// }
//moved to utils.c
// static void	copy_env(char **dst, char **src, int count)
// {
// 	int	i;

// 	i = 0;
// 	while (i < count)
// 	{
// 		dst[i] = ft_strdup(src[i]);
// 		i++;
// 	}
// }
//moved to utils.c
// static void	add_var(char *name, char *value, char ***env)
// {
// 	int		count;
// 	int		i;
// 	char	**new_env;
// 	char	*new_entry;

// 	count = 0;
// 	i = 0;
// 	while ((*env)[count])
// 		count++;
// 	new_env = malloc(sizeof(char *) * (count + 2));
// 	if (!new_env)
// 		return ;
// 	copy_env(new_env, *env, count);
// 	i = count;
// 	new_entry = build_env_entry(name, value);
// 	if (new_entry)
// 	{
// 		new_env[i] = new_entry;
// 		i++;
// 	}
// 	new_env[i] = NULL;
// 	free_envp(*env);
// 	*env = new_env;
// }
//moved to utils_02.c
// stahandle_joined_arg(char **args, int *i, char **name, char **value)
// {
// 	char	*joined;
// 	char	*eq;

// 	joined = ft_strjoin(args[*i], args[*i + 1]);
// 	if (!joined)
// 		return (1);
// 	eq = ft_strchr(joined, '=');
// 	*name = ft_substr(joined, 0, eq - joined);
// 	*value = ft_strdup(eq + 1);
// 	free(joined);
// 	*i += 2;
// 	return (0);
// }
//moved to utils_02.c
// static void	handle_simple_arg(char *arg, char **name, char **value)
// {
// 	char	*eq;

// 	eq = ft_strchr(arg, '=');
// 	*name = ft_substr(arg, 0, eq - arg);
// 	*value = ft_strdup(eq + 1);
// }
//moved to utils_02.c
// static void	update_or_add_var(char *name, char *value, char ***env)
// {
// 	int	j;
// 	int	found;

// 	found = 0;
// 	j = 0;
// 	while ((*env) && (*env)[j])
// 	{
// 		if (match_var((*env)[j], name))
// 		{
// 			update_var(name, value, env);
// 			found = 1;
// 			break ;
// 		}
// 		j++;
// 	}
// 	if (!found)
// 		add_var(name, value, env);
// }

static int	get_export_name_value(
	char **args,
	int *i,
	char **name,
	char **value
)
{
	char	*eq;

	*name = NULL;
	*value = NULL;
	eq = ft_strchr(args[*i], '=');
	if (eq && eq[1] == '\0' && args[*i + 1])
		return (handle_joined_arg(args, i, name, value));
	else if (eq)
	{
		handle_simple_arg(args[*i], name, value);
		(*i)++;
		return (0);
	}
	else
	{
		(*i)++;
		return (2);
	}
}

static int	process_export_argument(char **args, int *i, char ***env)
{
	char	*name;
	char	*value;
	int		ret;

	ret = get_export_name_value(args, i, &name, &value);
	if (ret == 1)
		return (1);
	if (ret == 2)
		return (0);
	if (name && value)
		update_or_add_var(name, value, env);
	free(name);
	free(value);
	return (0);
}

// static int	process_export_argument(char **args, int *i, char ***env)
// {
// 	char	*name;
// 	char	*value;
// 	char	*eq;

// 	name = NULL;
// 	value = NULL;
// 	eq = ft_strchr(args[*i], '=');
// 	if (eq && eq[1] == '\0' && args[*i + 1])
// 	{
// 		if (handle_joined_arg(args, i, &name, &value))
// 			return (1);
// 	}
// 	else if (eq)
// 	{
// 		handle_simple_arg(args[*i], &name, &value);
// 		(*i)++;
// 	}
// 	else
// 	{
// 		(*i)++;
// 		return (0);
// 	}
// 	if (name && value)
// 		update_or_add_var(name, value, env);
// 	free(name);
// 	free(value);
// 	return (0);
// }

int	builtin_export(char **args, char ***env)
{
	int	i;
	int	ret;

	i = 1;
	ret = 0;
	while (args[i])
	{
		ret = process_export_argument(args, &i, env);
		if (ret)
			break ;
	}
	return (ret);
}

// int	builtin_export(char **args, char ***env)
// {
// 	int		i;
// 	int		j;
// 	int		found;
// 	char	*eq;
// 	char	*name;
// 	char	*value;
// 	char	*joined;

// 	i = 1;
// 	while (args[i])
// 	{
// 		joined = NULL;
// 		name = NULL;
// 		value = NULL;
// 		eq = ft_strchr(args[i], '=');
// 		if (eq && eq[1] == '\0' && args[i + 1])
// 		{
// 			joined = ft_strjoin(args[i], args[i + 1]);
// 			if (!joined)
// 				return (1);
// 			eq = ft_strchr(joined, '=');
// 			name = ft_substr(joined, 0, eq - joined);
// 			value = ft_strdup(eq + 1);
// 			free(joined);
// 			i += 2;
// 		}
// 		else if (eq)
// 		{
// 			name = ft_substr(args[i], 0, eq - args[i]);
// 			value = ft_strdup(eq + 1);
// 			i++;
// 		}
// 		else
// 		{
// 			i++;
// 			continue ;
// 		}
// 		if (name && value)
// 		{
// 			found = 0;
// 			j = 0;
// 			while ((*env) && (*env)[j])
// 			{
// 				if (match_var((*env)[j], name))
// 				{
// 					update_var(name, value, env);
// 					found = 1;
// 					break ;
// 				}
// 				j++;
// 			}
// 			if (!found)
// 				add_var(name, value, env);
// 		}
// 		free(name);
// 		free(value);
// 	}
// 	return (0);
// }
