/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:23:16 by dfrincu           #+#    #+#             */
/*   Updated: 2025/05/16 12:59:24 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr = c;
		ptr++;
		n--;
	}
	return (s);
}
/*#include <stdio.h>
int main(void)
{
    // Ejemplo 1: Llenar una cadena con 'X'
    char str1[10] = "abcdefghi";
    ft_memset(str1, 'X', 5);
    printf("Ejemplo 1: %s\n", str1); "XXXXXfghi"

    // Ejemplo 2: Llenar toda la cadena con '\0' (borrar)
    char str2[10] = "Hola 42!";
    ft_memset(str2, '\0', 8); // ponemos 8 nulos
    printf("Ejemplo 2: %s\n", str2); // Espera: "" (string vacía)

    return 0;
}*/
