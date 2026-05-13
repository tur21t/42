/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 12:22:20 by dfrincu           #+#    #+#             */
/*   Updated: 2026/05/13 12:22:31 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_dollar_question(t_expand_ctx *ctx)
{
	char	*code;

	code = ft_itoa(g_signal);
	if (code)
	{
		if (ctx->j + ft_strlen(code) < 4096)
		{
			ft_strlcpy(ctx->result + ctx->j, code, 4096 - ctx->j);
			ctx->j += ft_strlen(code);
		}
		free(code);
	}
}

static void	handle_normal_char(const char *input, int *i, t_expand_ctx *ctx)
{
	if (ctx->j < 4095)
		ctx->result[ctx->j++] = input[(*i)++];
	else
		(*i)++;
}

void	expand_vars_loop(const char *input, t_expand_ctx *ctx, char **env)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '$' && input[i + 1] == '?')
		{
			handle_dollar_question(ctx);
			i += 2;
		}
		else if (input[i] == '$'
			&& (ft_isalnum(input[i + 1]) || input[i + 1] == '_'))
			handle_var(input, &i, ctx, env);
		else
			handle_normal_char(input, &i, ctx);
	}
	ctx->result[ctx->j] = '\0';
}
