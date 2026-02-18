/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:37:12 by dmtur             #+#    #+#             */
/*   Updated: 2025/12/15 11:05:27 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*parse_arguments(int argc, char **argv, int *out_count)
{
	char	**tokens;
	int		*values;
	int		token_count;

	tokens = NULL;
	values = NULL;
	token_count = 0;
	if (argc == 2)
		tokens = split_arguments(argv[1], &token_count);
	else
		tokens = split_arguments_from_argv(argv + 1, argc - 1, &token_count);
	if (!tokens || token_count == 0)
		return (NULL);
	if (!validate_number_tokens(tokens, token_count))
	{
		free_tokens(tokens);
		return (NULL);
	}
	values = convert_tokens_to_int_array(tokens, token_count);
	free_tokens(tokens);
	if (!values)
		return (NULL);
	*out_count = token_count;
	return (values);
}
