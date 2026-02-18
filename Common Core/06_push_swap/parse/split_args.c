/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:09:19 by dmtur             #+#    #+#             */
/*   Updated: 2025/12/15 16:42:28 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**split_arguments(const char *arg_string, int *out_count)
{
	char	**tokens;
	int		i;

	if (!arg_string)
		return (NULL);
	tokens = ft_split(arg_string, ' ');
	if (!tokens)
		return (NULL);
	i = 0;
	while (tokens[i])
		i++;
	*out_count = i;
	return (tokens);
}

char	**split_arguments_from_argv(char **argv, int argc, int *out_count)
{
	char	**tokens;
	int		i;

	tokens = malloc(sizeof(char *) * (argc + 1));
	if (!tokens)
		return (NULL);
	i = 0;
	while (i < argc)
	{
		tokens[i] = ft_strdup(argv[i]);
		if (!tokens[i])
		{
			free_tokens(tokens);
			return (NULL);
		}
		i++;
	}
	tokens[i] = NULL;
	*out_count = argc;
	return (tokens);
}

void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
