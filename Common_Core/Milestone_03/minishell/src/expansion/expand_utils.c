/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:55:50 by dmtur             #+#    #+#             */
/*   Updated: 2026/04/07 20:56:00 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_surrounded_by_single_quotes(const char *str)
{
	if (!str)
		return (0);
	while (*str == ' ')
		str++;
	if (*str == '\'' && str[ft_strlen(str) - 1] == '\'')
		return (1);
	return (0);
}

void	expand_token_list(t_token *tokens, char **env)
{
	t_token	*curr;
	char	*expanded;

	curr = tokens;
	while (curr)
	{
		if (curr->type == T_WORD  && curr->quote != '\''
			&& !is_surrounded_by_single_quotes(curr->value))
		{
			expanded = expand_vars(curr->value, env);
			free(curr->value);
			curr->value = expanded;
		}
		curr = curr->next;
	}
}
