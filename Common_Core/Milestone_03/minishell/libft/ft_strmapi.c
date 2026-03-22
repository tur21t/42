/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 15:56:29 by dfrincu           #+#    #+#             */
/*   Updated: 2025/05/27 18:10:50 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*result;

	if (!s || !f)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*#include <stdio.h>
// Esta función convertirá cada letra a mayúscula SI está en minúscula
char to_upper_with_index(unsigned int i, char c)
{
    (void)i; // No usamos el índice en este ejemplo
    if (c >= 'a' && c <= 'z')
        return (c - 32); // Convierte a mayúscula
    return c;
}

int main(void)
{
    char *original = "Hola mundo!";
    char *modificada;

    modificada = ft_strmapi(original, to_upper_with_index);

    if (modificada)
    {
        printf("Original:   %s\n", original);
        printf("Modificada: %s\n", modificada);
        free(modificada);
    }
    else
    {
        printf("Error: No se pudo asignar memoria.\n");
    }

    return 0;
}*/
