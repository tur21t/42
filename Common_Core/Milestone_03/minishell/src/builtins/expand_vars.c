/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 11:32:02 by dmtur             #+#    #+#             */
/*   Updated: 2026/04/01 11:32:11 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Helper: get value of VAR from env
char	*get_env_value(char **env, char *name)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(name);
	while (env && env[i])
	{
		if (ft_strncmp(env[i], name, len) == 0 && env[i][len] == '=')
			return (env[i] + len + 1);
		i++;
	}
	return ("");
}

// Main expansion function
static int	handle_var(const char *input, int *i, t_expand_ctx *ctx, char **env)
{
	char	var[256];
	int		k;
	char	*val;

	k = 0;
	(*i)++;
	while (input[*i] && (ft_isalnum(input[*i]) || input[*i] == '_'))
		var[k++] = input[(*i)++];
	var[k] = '\0';
	val = get_env_value(env, var);
	ft_strlcpy(ctx->result + ctx->j, val, ft_strlen(val) + 1);
	ctx->j += ft_strlen(val);
	return (0);
}

char	*expand_vars(const char *input, char **env)
{
	char			*result;
	int				i;
	t_expand_ctx	ctx;

	result = malloc(4096);
	if (!result)
		return (NULL);
	i = 0;
	ctx.j = 0;
	ctx.result = result;
	while (input[i])
	{
		if (input[i] == '$'
			&& (ft_isalpha(input[i + 1]) || input[i + 1] == '_'))
			handle_var(input, &i, &ctx, env);
		else
			result[ctx.j++] = input[i++];
	}
	result[ctx.j] = '\0';
	return (result);
}

/*void expand_args(char **args, char *quotes, char **env)
{
    int i = 1;
    char *expanded;

    while (args && args[i])
    {
        if (quotes[i] != '\'') // Solo expande si NO es comilla simple
        {
            expanded = expand_vars(args[i], env);
            free(args[i]);
            args[i] = expanded;
        }
        i++;
    }
}*/