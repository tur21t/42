/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:06:34 by dfrincu           #+#    #+#             */
/*   Updated: 2026/03/09 16:40:48 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_redir(t_token **tokens, char *input, int i)
{
	if (input[i] == '<' && input[i + 1] == '<')
	{
		add_token(tokens, "<<", T_HEREDOC);
		i += 2;
	}
	else if (input[i] == '>' && input[i + 1] == '>')
	{
		add_token(tokens, ">>", T_REDIR_APPEND);
		i += 2;
	}
	else if (input[i] == '<')
	{
		add_token(tokens, "<", T_REDIR_IN);
		i++;
	}
	else if (input[i] == '>')
	{
		add_token(tokens, ">", T_REDIR_OUT);
		i++;
	}
	return (i);
}

int	handle_word(t_token **tokens, char *input, int i)
{
	int		start;
	char	*word;
	char	*clean_word;

	start = i;
	i = get_word_end(input, i);
	word = ft_substr(input, start, i - start);
	clean_word = remove_quotes(word);
	add_token(tokens, clean_word, T_WORD);
	free(word);
	free(clean_word);
	return (i);
}

t_token	*lexer(char *input)
{
	int		i;
	t_token	*tokens;

	tokens = NULL;
	i = 0;
	while (input[i])
	{
		if (input[i] == ' ' || input[i] == '\t')
			i++;
		else if (input[i] == '|')
		{
			add_token(&tokens, "|", T_PIPE);
			i++;
		}
		else if (input[i] == '<' || input[i] == '>')
			i = handle_redir(&tokens, input, i);
		else
			i = handle_word(&tokens, input, i);
	}
	return (tokens);
}

void	add_token(t_token **tokens, char *value, t_token_type type)
{
	t_token	*new;
	t_token	*last;

	new = malloc(sizeof(t_token));
	if (!new)
		return ;
	new->value = ft_strdup(value);
	new->type = type;
	new->next = NULL;
	if (*tokens == NULL)
	{
		*tokens = new;
		return ;
	}
	else
	{
		last = *tokens;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

void	free_tokens(t_token *tokens)
{
	t_token	*tmp;

	while (tokens)
	{
		tmp = tokens->next;
		free(tokens->value);
		free(tokens);
		tokens = tmp;
	}
}
