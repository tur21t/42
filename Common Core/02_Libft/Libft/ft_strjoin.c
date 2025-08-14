/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:58:42 by dmtur             #+#    #+#             */
/*   Updated: 2025/06/16 20:15:54 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_strcpycat(char *dst, char const *s1, char const *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!joined)
		return (NULL);
	ft_strcpycat(joined, s1, s2);
	return (joined);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*joined;

	joined = ft_strjoin("Namo Arya Taraye, ", "Om Tare Tuttare Ture Svaha");
	if (joined)
	{
		printf("%s\n", joined);
		free(joined);
	}
	joined = ft_strjoin("Om Tare Tuttare Ture Svaha", "");
	if (joined)
	{
		printf("%s\n", joined);
		free(joined);
	}
	joined = ft_strjoin("", "");
	if (joined)
	{
		printf("%s\n", joined);
		free(joined);
	}
	joined = ft_strjoin("", "Sarva Mangalam");
	if (joined)
	{
		printf("%s\n", joined);
		free(joined);
	}
	return (0);
}*/
