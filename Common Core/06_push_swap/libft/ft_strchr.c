/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:13:59 by dmtur             #+#    #+#             */
/*   Updated: 2025/06/09 22:13:20 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	const char	*str = "Om Tare Tuttare Ture Svaha";
	int	ch = 'T';

	printf("Original string : %s\n", str);
	printf("Character to find: '%c'\n", ch);
	printf("ft_strchr result : %s\n", ft_strchr(str, ch));
	printf("strchr result    : %s\n", strchr(str, ch));

	return (0);
}*/
