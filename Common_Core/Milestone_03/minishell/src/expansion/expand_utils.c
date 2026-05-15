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

void	free_token_chain(t_token *t)
{
	t_token	*n;

	while (t)
	{
		n = t->next;
		free(t->value);
		free(t);
		t = n;
	}
}

t_token	*new_word_token_take(char *value, t_token *next)
{
	t_token	*t;

	t = malloc(sizeof(*t));
	if (!t)
	{
		free(value);
		return (NULL);
	}
	t->type = T_WORD;
	t->quote = 0;
	t->value = value;
	t->next = next;
	return (t);
}

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

int	is_ws(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

void	delete_token(t_token **head, t_token *curr, t_token *prev)
{
	if (!head || !*head || !curr)
		return ;
	if (prev)
		prev->next = curr->next;
	else
		*head = curr->next;
	free(curr->value);
	free(curr);
}
