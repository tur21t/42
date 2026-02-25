/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 21:18:35 by dmtur             #+#    #+#             */
/*   Updated: 2026/02/25 21:12:17 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    **ft_split(char *str)
{
	char	**result = 0;
	int	i = 0;//str index
	int	j = 0;//index of array element
	int	k = 0;//index of str inside of array element

	result = malloc(1021);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
		{
			k = 0;
			result[j] = malloc(108);
			while (str[i] && str[i] != ' ' && str[i] != '\t')
			{
				result[j][k] = str[i];
				k++;
				i++;
			}
			result[j][k] = '\0';
			j++;
		}
		else
			i++;
	}
	result[j] = NULL;
	return (result);
}


#include <stdio.h>

int main(void)
{
    char **words;
    int i = 0;

    words = ft_split("   hello   world\t42  school   ");

    while (words[i])
    {
        printf("word[%d]: %s\n", i, words[i]);
        i++;
    }

    return 0;
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

char    **ft_split(char *str);
--------------------------------------------------------------------------------
#include <stdlib.h>

char    **ft_split(char *str)
{
    int i;
    int j;
    int k;
    char **tab;

    i = 0;
    j = 0;
    tab = malloc(sizeof(char *) * 100);
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while(str[i])
    {
        if (str[i] != ' ' && str[i] != '\t')
        {
            k = 0;
            tab[j] = malloc(sizeof(char *) * 100);
            while(str[i] != ' ' && str[i] != '\t' && str[i])
            {
                tab[j][k] = str[i];
                i++;
                k++;
            }
            tab[j][k] = '\0';
            j++;
        }
        else
            i++;
    }
    tab[j] = 0;
    return (tab);
}
----------- my first version correct --------------------------------
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
		while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			i++;
	}
	
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);

	i = 0;

	while(str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			i++;
		start = i;
		while (str[i] != '\0' && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
			i++;
		if (i > start)
		{
			result[j] = malloc(i - start + 1);
			if(!result[j])
				return (NULL);
			k = 0;
			while (start < i)
			{
				result[j][k] = str[start];
				k++;
				start++;
			}
			result[j][k] = '\0';
		       j++;	
		}
	}
	result[j] = NULL;
	return (result);
}





*/
/*
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
}*/
