/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 21:18:35 by dmtur             #+#    #+#             */
/*   Updated: 2026/02/17 22:05:51 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_split(char *str)
{
	char	**result;
	int	i = 0;
	int	j = 0;
	int	k = 0;
	int	words = 0;
	int	start;

	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i] != '\0')
			words++;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
	}
	
	result = malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);

	i = 0;

	while(str[i] != '\0')
	{
		while (str[i] == ' ' || s[i] == '\n' || str[i] == '\t')
			i++;
		start = i;

	}
	return (out)
}
/*Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);*/

int	count_words(char *str)
{
	int	i = 0;
	int	count = 0;

	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\t' || str [i] == '\n')
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
	}
	return (count);
}


