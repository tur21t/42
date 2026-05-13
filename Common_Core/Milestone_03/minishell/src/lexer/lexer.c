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

static int	lex_consume_quote(t_token **toks, char *in, int i, int *start)
{
	char	quote;
	int		qstart;

	if (i > *start)
		add_sub(toks, in, *start, i);
	quote = in[i];
	i++;
	qstart = i;
	while (in[i] && in[i] != quote)
		i++;
	add_sub_q(toks, in, qstart, i);
	if (in[i] == quote)
		i++;
	*start = i;
	return (i);
}

int	handle_redir(t_token **tokens, char *input, int i)
{
	if (input[i] == '<' && input[i + 1] == '<')
	{
		add_token(tokens, "<<", T_HEREDOC, 0);
		i += 2;
	}
	else if (input[i] == '>' && input[i + 1] == '>')
	{
		add_token(tokens, ">>", T_REDIR_APPEND, 0);
		i += 2;
	}
	else if (input[i] == '<')
	{
		add_token(tokens, "<", T_REDIR_IN, 0);
		i++;
	}
	else if (input[i] == '>')
	{
		add_token(tokens, ">", T_REDIR_OUT, 0);
		i++;
	}
	return (i);
}

// Main word handler: splits at quote boundaries
/*int	handle_word(t_token **tokens, char *input, int i)
{
	int		start;
	char	quote;
	int		qstart;

	start = i;
	while (input[i] && input[i] != ' ' && input[i] != '\t'
		&& input[i] != '|' && input[i] != '<' && input[i] != '>')
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			if (i > start)
				add_sub(tokens, input, start, i);
			quote = input[i++];
			qstart = i;
			while (input[i] && input[i] != quote)
				i++;
			add_sub_q(tokens, input, qstart, i);
			if (input[i] == quote)
				i++;
			start = i;
		}
		else
			i++;
	}
	if (i > start)
		add_sub(tokens, input, start, i);
	return (i);
}*/

int	handle_word(t_token **tokens, char *input, int i)
{
	int	start;

	start = i;
	while (input[i] && input[i] != ' ' && input[i] != '\t'
		&& input[i] != '|' && input[i] != '<' && input[i] != '>')
	{
		if (input[i] == '\'' || input[i] == '"')
			i = lex_consume_quote(tokens, input, i, &start);
		else
			i++;
	}
	if (i > start)
		add_sub(tokens, input, start, i);
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
			add_token(&tokens, "|", T_PIPE, 0);
			i++;
		}
		else if (input[i] == '<' || input[i] == '>')
			i = handle_redir(&tokens, input, i);
		else
			i = handle_word(&tokens, input, i);
	}
	return (tokens);
}

void	add_token(t_token **tokens, char *value, t_token_type type, char quote)
{
	t_token	*new;
	t_token	*last;

	new = malloc(sizeof(t_token));
	if (!new)
		return ;
	new->value = ft_strdup(value);
	new->type = type;
	new->quote = quote;
	new->next = NULL;
	if (*tokens == NULL)
	{
		*tokens = new;
		return ;
	}
	last = *tokens;
	while (last->next)
		last = last->next;
	last->next = new;
}
