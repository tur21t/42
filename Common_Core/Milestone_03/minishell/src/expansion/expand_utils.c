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

static void	free_token_chain(t_token *t)
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

static t_token	*new_word_token_take(char *value, t_token *next)
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

static int	is_ws(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static void	delete_token(t_token **head, t_token *curr, t_token *prev)
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

static int	split_token_words(t_token **head, t_token *curr, t_token *prev)
{
	char	*orig;
	t_token	*orig_next;
	int		i;
	int		start;
	int		first;
	int		replaced;
	t_token	*tail;
	char	*part;
	int		ok;

	if (!curr || !curr->value)
		return (1);
	orig = curr->value;
	orig_next = curr->next;
	i = 0;
	first = 1;
	replaced = 0;
	tail = curr;
	ok = 1;
	while (orig[i])
	{
		while (orig[i] && is_ws(orig[i]))
			i++;
		if (!orig[i])
			break ;
		start = i;
		while (orig[i] && !is_ws(orig[i]))
			i++;
		part = ft_substr(orig, start, i - start);
		if (!part)
		{
			ok = 0;
			break ;
		}
		if (first)
		{
			curr->value = part;
			first = 0;
			replaced = 1;
		}
		else
		{
			t_token	*nt;

			nt = new_word_token_take(part, tail->next);
			if (!nt)
			{
				free(part);
				ok = 0;
				break ;
			}
			tail->next = nt;
			tail = nt;
		}
	}
	if (!ok)
	{
		if (replaced)
		{
			free(curr->value);
			curr->value = orig;
			free_token_chain(curr->next);
			curr->next = orig_next;
		}
		else
		{
			free (orig);
		}
		return (1);
	}
	if (first)
	{
		curr->value = orig;
		delete_token(head, curr, prev);
		return (0);
	}
	free(orig);
	return (1);
}

void	expand_token_list(t_token **tokens, char **env)
{
	t_token	*curr;
	t_token	*prev;
	char	*expanded;

	curr = *tokens;
	prev = NULL;
	while (curr)
	{
		if (curr->type == T_HEREDOC && curr->next)
		{
			prev = curr->next;
			curr = curr->next->next;
			continue ;
		}
		if (curr->type == T_WORD && curr->quote != '\''
			&& !is_surrounded_by_single_quotes(curr->value))
		{
			expanded = expand_vars(curr->value, env);
			free(curr->value);
			curr->value = expanded;
			if (curr->quote == 0 && curr->value)
			{
				if (!split_token_words(tokens, curr, prev))
				{
					curr = (prev) ? prev->next : *tokens;
					continue ;
				}
			}
		}
		prev = curr;
		curr = curr->next;
	}
}
