/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 09:35:25 by dfrincu           #+#    #+#             */
/*   Updated: 2025/05/22 11:36:45 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}
/*#include <stdio.h>
int main(void)
{
    char dest[10];
    size_t ret;

    ret = ft_strlcpy(dest, "Hola mundo!", sizeof(dest));
    printf("Copiado: '%s', longitud src: %zu\n", dest, ret); 
    // Copia "Hola mund", devuelve 11

    ret = ft_strlcpy(dest, "Hi", sizeof(dest));
    printf("Copiado: '%s', longitud src: %zu\n", dest, ret); 
    // Copia "Hi", devuelve 2

    ret = ft_strlcpy(dest, "123456789", 5);
    printf("Copiado: '%s', longitud src: %zu\n", dest, ret); 
    // Copia "1234", devuelve 9

    return 0;
}*/
