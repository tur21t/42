/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_support.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:56:22 by dfrincu           #+#    #+#             */
/*   Updated: 2026/03/11 14:56:24 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	get_unclosed_quote(const char *input)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (input[i])
	{
		if (!quote && (input[i] == '\'' || input[i] == '"'))
			quote = input[i];
		else if (quote && input[i] == quote)
			quote = 0;
		i++;
	}
	return (quote);
}

int	get_word_end(char *input, int i)
{
	char	quote;

	while (input[i] && input[i] != ' ' && input[i] != '\t'
		&& input[i] != '|' && input[i] != '<' && input[i] != '>')
	{
		if (input[i] == '"' || input[i] == '\'')
		{
			quote = input[i++];
			while (input[i] && input[i] != quote)
				i++;
			if (input[i] == quote)
				i++;
		}
		else
			i++;
	}
	return (i);
}

char	*remove_quotes_and_detect(const char *str, char *quote_type)
{
	char	*res;
	int		i;
	int		j;
	char	quote;

	i = 0;
	j = 0;
	quote = 0;
	res = malloc(ft_strlen(str) + 1);
	if (!res)
		return (NULL);
	while (str[i])
	{
		if ((str[i] == '\'' || str[i] == '"') && !quote)
		{
			quote = str[i++];
			*quote_type = quote;
			while (str[i] && str[i] != quote)
				res[j++] = str[i++];
			if (str[i] == quote)
				i++;
			quote = 0;
		}
		else
			res[j++] = str[i++];
	}
	res[j] = '\0';
	return (res);
}
