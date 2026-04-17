/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 22:20:37 by dmtur             #+#    #+#             */
/*   Updated: 2025/06/15 22:38:33 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_isset(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_isset(s1[start], set))
		start++;
	end = start;
	while (s1[end])
		end++;
	while (end > start && ft_isset(s1[end - 1], set))
		end--;
	trimmed = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!trimmed)
		return (NULL);
	i = 0;
	while (start < end)
		trimmed[i++] = s1[start++];
	trimmed[i] = '\0';
	return (trimmed);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*trimmed;

	trimmed = ft_strtrim("  Om Tare Tuttare Ture Svaha  ", " ");
	if (trimmed)
	{
		printf("Trimmed: \"%s\"\n", trimmed);
		free(trimmed);
	}
	trimmed = ft_strtrim("...hello...", ".");
	if (trimmed)
	{
		printf("Trimmed: \"%s\"\n", trimmed);
		free(trimmed);
	}
	trimmed = ft_strtrim("xxxx", "x");
	if (trimmed)
	{
		printf("Trimmed: \"%s\"\n", trimmed);
		free(trimmed);
	}	return (0);
}*/
