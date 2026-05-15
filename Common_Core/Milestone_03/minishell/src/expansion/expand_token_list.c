/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 13:19:20 by dfrincu           #+#    #+#             */
/*   Updated: 2026/05/13 13:19:39 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_heredoc_case(t_token **curr, t_token **prev)
{
	*prev = (*curr)->next;
	*curr = (*curr)->next->next;
}

static void	handle_split_case(t_token **tokens, t_token **curr, t_token *prev)
{
	if (prev)
		*curr = prev->next;
	else
		*curr = *tokens;
}

static int	process_token_expansion(t_token **tokens,
	t_token *curr, t_token *prev, char **env)
{
	char	*expanded;

	if (curr->type == T_HEREDOC && curr->next)
	{
		return (2);
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
				return (1);
			}
		}
	}
	return (0);
}

void	expand_token_list(t_token **tokens, char **env)
{
	t_token	*curr;
	t_token	*prev;
	int		res;

	curr = *tokens;
	prev = NULL;
	while (curr)
	{
		res = process_token_expansion(tokens, curr, prev, env);
		if (res == 2)
		{
			handle_heredoc_case(&curr, &prev);
			continue ;
		}
		if (res == 1)
		{
			handle_split_case(tokens, &curr, prev);
			continue ;
		}
		prev = curr;
		curr = curr->next;
	}
}
