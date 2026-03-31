/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 23:42:09 by dmtur             #+#    #+#             */
/*   Updated: 2026/03/31 23:42:25 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//#include <unistd.h>
//#include <stdio.h>

static char	*get_env_value(char **env, char *name)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(name);
	while (env && env[i])
	{
		if (ft_strncmp(env[i], name, len) == 0 && env[i][len] == '=')
			return (env[i] + len + 1);
		i++;
	}
	return (NULL);
}

int	builtin_cd(char **args, char ***env)
{
	char	oldpwd[PATH_MAX];
	char	*target;
	char	*home;

	if (!getcwd(oldpwd, sizeof(oldpwd)))
		return (perror("cd"), 1);
	if (args[1])
		target = args[1];
	else
	{
		home = get_env_value(*env, "HOME");
		if (!home)
			return (printf("cd: HOME not set\n"), 1);
		target = home;
	}
	if (chdir(target) != 0)
		return (perror("cd"), 1);
	builtin_export((char *[]){"export", "OLDPWD", oldpwd, NULL}, env);
	if (getcwd(oldpwd, sizeof(oldpwd)))
		builtin_export((char *[]){"export", "PWD", oldpwd, NULL}, env);
	return (0);
}
