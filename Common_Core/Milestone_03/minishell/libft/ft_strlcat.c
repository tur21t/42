/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:23:06 by dfrincu           #+#    #+#             */
/*   Updated: 2025/05/16 15:56:02 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	int		i;

	dest_len = 0;
	i = 0;
	while (dest_len < size && dest[dest_len])
		dest_len++;
	if (dest_len == size)
		return (dest_len + ft_strlen(src));
	while (src[i] && (dest_len + i) < (size - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + ft_strlen(src));
}
/*#include <stdio.h>
int main(void)
{
    char dest[20] = "Hola";
    const char *src = " mundo";

    size_t ret = ft_strlcat(dest, src, sizeof(dest));

    printf("Cadena concatenada: '%s'\n", dest);
    printf("Longitud total que intentó crear: %zu\n", ret);

    // Caso cuando no hay suficiente espacio
    char dest2[10] = "12345";
    const char *src2 = "6789ABC";

    ret = ft_strlcat(dest2, src2, sizeof(dest2));

    printf("Concatenación con buffer pequeño: '%s'\n", dest2);
    printf("Longitud total que intentó crear: %zu\n", ret);

    return 0;
}*/
