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

static void	print_export_env(char **env)
{
	int		i;
	char	*eq;

	i = 0;
	while (env && env[i])
	{
		eq = ft_strchr(env[i], '=');
		printf("declare -x ");
		if (eq)
			printf("%.*s=\"%s\"\n", (int)(eq - env[i]), env[i], eq + 1);
		else
			printf("%s\n", env[i]);
		i++;
	}
}

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

int	builtin_export(char **args, char ***env)
{
	int	i;
	int	ret;

	i = 1;
	ret = 0;
	if (!args[1])
	{
		print_export_env(*env);
		return (0);
	}
	while (args[i])
	{
		ret = process_export_argument(args, &i, env);
		if (ret)
			break ;
	}
	return (ret);
}
