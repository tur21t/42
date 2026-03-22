/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:01:39 by dfrincu           #+#    #+#             */
/*   Updated: 2025/05/27 13:00:18 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += n;
		s += n;
		while (n > 0)
		{
			d--;
			s--;
			*d = *s;
			n--;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
    char str1[20] = "Hello, World!";
    char str2[20] = "Hello, World!";

    // Caso 1: sin solapamiento
    printf("Antes ft_memmove sin solapamiento: %s\n", str1);
    ft_memmove(str1 + 7, str1, 5);
    printf("Después ft_memmove sin solapamiento: %s\n", str1);

    // Restaurar la cadena
    strcpy(str1, "Hello, World!");

    // Caso 2: con solapamiento (copiar hacia adelante, zonas que se pisan)
    printf("\nAntes ft_memmove con solapamiento: %s\n", str2);
    ft_memmove(str2 + 2, str2, 10);
    printf("Después ft_memmove con solapamiento: %s\n", str2);

    return 0;
}*/
