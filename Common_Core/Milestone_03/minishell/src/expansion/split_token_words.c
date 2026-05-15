/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_token_words.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 13:19:49 by dfrincu           #+#    #+#             */
/*   Updated: 2026/05/13 13:20:04 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Helper para crear y enlazar un nuevo token

static int	add_new_word_token(t_split_ctx *ctx, char *part)
{
	t_token	*nt;

	nt = new_word_token_take(part, ctx->tail->next);
	if (!nt)
	{
		free(part);
		ctx->ok = 0;
		return (0);
	}
	ctx->tail->next = nt;
	ctx->tail = nt;
	return (1);
}

// Helper para extraer la siguiente palabra
static char	*get_next_word(const char *orig, int *i)
{
	int	start;
	int	len;

	while (orig[*i] && is_ws(orig[*i]))
		(*i)++;
	if (!orig[*i])
		return (NULL);
	start = *i;
	while (orig[*i] && !is_ws(orig[*i]))
		(*i)++;
	len = *i - start;
	return (ft_substr(orig, start, len));
}

static void	split_token_words_loop(t_split_ctx *ctx)
{
	char	*part;

	while (ctx->orig[ctx->i])
	{
		part = get_next_word(ctx->orig, &ctx->i);
		if (!part)
			break ;
		if (ctx->first)
		{
			ctx->tail->value = part;
			ctx->first = 0;
			ctx->replaced = 1;
		}
		else if (!add_new_word_token(ctx, part))
			break ;
	}
}
// Helper para rollback en error

static void	rollback_split(t_token *curr, t_split_ctx *ctx)
{
	if (ctx->replaced)
	{
		free(curr->value);
		curr->value = ctx->orig;
		free_token_chain(curr->next);
		curr->next = ctx->orig_next;
	}
	else
		free(ctx->orig);
}

int	split_token_words(t_token **head, t_token *curr, t_token *prev)
{
	t_split_ctx	ctx;

	if (!curr || !curr->value)
		return (1);
	init_split_ctx(&ctx, curr);
	split_token_words_loop(&ctx);
	if (!ctx.ok)
	{
		rollback_split(curr, &ctx);
		return (1);
	}
	if (ctx.first)
	{
		curr->value = ctx.orig;
		delete_token(head, curr, prev);
		return (0);
	}
	free(ctx.orig);
	return (1);
}
