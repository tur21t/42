/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:54:18 by dfrincu           #+#    #+#             */
/*   Updated: 2025/05/16 14:17:00 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	i = 0;
	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (p1[i] != p2[i])
		{
			return (p1[i] - p2[i]);
		}
		i++;
	}
	return (0);
}
/*#include <stdio.h>
int main(void)
{
    // Caso 1: bytes idénticos en primeros 'n' bytes
    printf("1. abc vs abc, n=2: %d\n", ft_memcmp("abc", "abc", 2));
                                                // Debe dar 0
    // Caso 2: diferencia en bytes dentro de 'n'
    printf("2. abc vs abd, n=3: %d\n", ft_memcmp("abc", "abd", 3));
                                                // Negativo (ej: -1)
    // Caso 3: comparar bytes con '\0' incluidos
    printf("3. abc vs ab\\0, n=3: %d\n", ft_memcmp("abc", "ab\0", 3));
                                                // Positivo (ej: 'c' - 0 = > 0)
    // Caso 4: n=0 (no compara nada)
    printf("4. abc vs def, n=0: %d\n", ft_memcmp("abc", "def", 0));
                                                // Debe dar 0
    // Caso 5: n mayor que la longitud de ambas
    printf("5. abc vs abc, n=5: %d\n", ft_memcmp("abc", "abc", 5));
                                                // Debe dar 0 si no hay dif
    // Caso 6: diferencia justo en el byte n-1
    printf("6. abc vs abx, n=3: %d\n", ft_memcmp("abc", "abx", 3));
                                                // Negativo (ej: 'c' - 'x' < 0)
    return 0;
}*/
