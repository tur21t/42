/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_support02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 11:00:13 by dfrincu           #+#    #+#             */
/*   Updated: 2026/05/13 11:00:55 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_token_from_substr(t_lex_sub *s)
{
	char	*substr;

	substr = ft_substr(s->input, s->start, s->end - s->start);
	if (!substr)
		return ;
	add_token(s->tokens, substr, T_WORD, s->quote);
	free(substr);
}

void	add_sub(t_token **toks, const char *in, int st, int en)
{
	t_lex_sub	s;

	s.tokens = toks;
	s.input = in;
	s.start = st;
	s.end = en;
	s.quote = 0;
	add_token_from_substr(&s);
}

void	add_sub_q(t_token **toks, const char *in, int st, int en)
{
	t_lex_sub	s;

	s.tokens = toks;
	s.input = in;
	s.start = st;
	s.end = en;
	s.quote = in[st - 1];
	add_token_from_substr(&s);
}
