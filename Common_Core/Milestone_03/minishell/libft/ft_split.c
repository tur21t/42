/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 10:55:27 by dfrincu           #+#    #+#             */
/*   Updated: 2025/06/12 15:24:44 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_strcount(char const *s, char c)
{
	size_t	str_count;
	int		in_sub;

	str_count = 0;
	in_sub = 0;
	while (*s)
	{
		if (*s != c && !in_sub)
		{
			in_sub = 1;
			str_count++;
		}
		else if (*s == c)
			in_sub = 0;
		s++;
	}
	return (str_count);
}

static void	ft_free_array(char **array, size_t index)
{
	while (index > 0)
		free(array[--index]);
	free(array);
}

static int	ft_fill_array(char **array, const char *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	start = 0;
	while (s[start])
	{
		if (s[start] != c)
		{
			end = start;
			while (s[end] && s[end] != c)
				end++;
			array[i] = ft_substr(s, start, end - start);
			if (!array[i])
				return (ft_free_array(array, i), 0);
			i++;
			start = end;
		}
		else
			start++;
	}
	array[i] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**s_array;

	if (!s)
		return (NULL);
	s_array = malloc((ft_strcount(s, c) + 1) * sizeof(char *));
	if (!s_array)
		return (NULL);
	if (!ft_fill_array(s_array, s, c))
		return (NULL);
	return (s_array);
}
