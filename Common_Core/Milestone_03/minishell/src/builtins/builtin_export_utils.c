/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 21:41:58 by dmtur             #+#    #+#             */
/*   Updated: 2026/03/23 21:42:17 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	match_var(const char *env_entry, const char *name)
{
	size_t	len;

	len = ft_strlen(name);
	return (ft_strncmp(env_entry, name, len) == 0 && env_entry[len] == '=');
}

void	update_var(char *name, char *value, char ***env)
{
	int		j;
	char	*new_entry;
	size_t	name_len;
	size_t	value_len;

	j = 0;
	name_len = ft_strlen(name);
	value_len = ft_strlen(value);
	while ((*env)[j])
	{
		if (match_var((*env)[j], name))
		{
			free((*env)[j]);
			new_entry = malloc(name_len + value_len + 2);
			if (new_entry)
			{
				ft_strlcpy(new_entry, name, name_len + 1);
				new_entry[name_len] = '=';
				ft_strlcpy(new_entry + name_len + 1, value, value_len + 1);
				(*env)[j] = new_entry;
			}
			return ;
		}
		j++;
	}
}
