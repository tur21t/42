/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:42:31 by dmtur             #+#    #+#             */
/*   Updated: 2025/06/11 17:25:05 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] && haystack[i + j] == needle[j] && (i + j) < len)
			j++;
		if (!needle[j])
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

char *ft_strnstr(const char *haystack, const char *needle, size_t len);

int main(void)
{
	const char *haystack = "Om Tare Tuttare Ture Svaha";
	const char *needle = "Ture";
	size_t len = 25;

	printf("Haystack: \"%s\"\n", haystack);
	printf("Needle  : \"%s\"\n", needle);
	printf("Limit   : %zu characters\n", len);

	printf("ft_strnstr result: %s\n", ft_strnstr(haystack, needle, len));
//	printf("strnstr result   : %s\n", strnstr(haystack, needle, len));
	return	(0);
}*/
