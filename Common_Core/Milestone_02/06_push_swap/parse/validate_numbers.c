/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:07:13 by dmtur             #+#    #+#             */
/*   Updated: 2025/12/15 17:26:32 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	validate_integer_string(const char *str)
{
	int	i;

	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	validate_number_tokens(char **tokens, int count)
{
	int		i;
	int		j;
	long	value_i;
	long	value_j;

	i = 0;
	while (i < count)
	{
		if (!validate_integer_string(tokens[i]))
			return (0);
		value_i = ft_atoi(tokens[i]);
		if (value_i > 2147483647 || value_i < -2147483648)
			return (0);
		j = i + 1;
		while (j < count)
		{
			value_j = ft_atoi(tokens[j]);
			if (value_i == value_j)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	*convert_tokens_to_int_array(char **tokens, int count)
{
	int	*values;
	int	i;

	values = malloc(sizeof(int) * count);
	if (!values)
		return (NULL);
	i = 0;
	while (i < count)
	{
		values[i] = (int)ft_atoi(tokens[i]);
		i++;
	}
	return (values);
}
