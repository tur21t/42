/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 21:14:05 by dmtur             #+#    #+#             */
/*   Updated: 2025/06/08 22:08:03 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	if (src == NULL && dst == NULL)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
    char	src[] = "Om Tare Tuttare Ture Svaha";
    char	dst1[50];
    char	dst2[50];
    size_t	n = 26;

    ft_memcpy(dst1, src, n);
    dst1[n] = '\0';

    memcpy(dst2, src, n);
    dst2[n] = '\0';

    printf("Source   : %s\n", src);
    printf("ft_memcpy: %s\n", dst1);
    printf("memcpy   : %s\n", dst2);

    if (memcmp(dst1, dst2, n) == 0)
        printf("ft_memcpy matches memcpy\n");
    else
        printf("Difference found\n");

    return (0);
}*/
