/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 22:14:57 by dmtur             #+#    #+#             */
/*   Updated: 2025/06/09 20:14:10 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	if (dst < src)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (dst > src)
	{
		i = n;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int     main(void)
{
	char        str1[50] = "Om Tare Tuttare Ture Svaha";
	char        str2[50] = "Om Tare Tuttare Ture Svaha";
	size_t      n = 26;

	ft_memmove(str1 + 3, str1, n);

	memmove(str2 + 3, str2, n);

	printf("ft_memmove: %s\n", str1);
	printf("memmove   : %s\n", str2);

	if (memcmp(str1, str2, sizeof(str1)) == 0)
		printf("ft_memmove matches memmove\n");
	else
		printf("Difference found\n");
	
	return (0);
}*/
