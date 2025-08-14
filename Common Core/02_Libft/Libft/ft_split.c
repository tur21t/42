/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 21:21:33 by dmtur             #+#    #+#             */
/*   Updated: 2025/06/15 22:12:46 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*ft_worddup(const char *start, const char *end)
{
	int		len;
	char	*word;
	int		i;

	len = end - start;
	i = 0;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i++] = *start;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	int			i;
	const char	*start;

	i = 0;
	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			result[i++] = ft_worddup(start, s);
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}
/*
#include <stdio.h>

int	main(void)
{
	char	**result;
	int		i;

	result = ft_split("Om Tare Tuttare Ture Svaha", ' ');
	if (!result)
		return (1);
	i = 0;
	while (result[i])
	{
		printf("Word %d: %s\n", i, result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}*/
