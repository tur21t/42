/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:17:19 by dfrincu           #+#    #+#             */
/*   Updated: 2025/05/16 15:28:44 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*#include <stdio.h>
int main() {
    // Caso 1: Cadenas idénticas en los primeros 'n' caracteres
    printf("1. abc vs abc, n=2: %d\n", ft_strncmp("abc", "abc", 2));  
                                                        // Debe dar 0
    // Caso 2: Diferencias dentro de los primeros 'n' caracteres
    printf("2. abc vs abd, n=3: %d\n", ft_strncmp("abc", "abd", 3));  
                                                // Negativo (ej: -1)
    // Caso 3: Una cadena es más corta que 'n'
    printf("3. abc vs ab, n=3: %d\n", ft_strncmp("abc", "ab", 3));
                                                // Positivo (ej: 99)
    // Caso 4: n=0 (no se compara nada)
    printf("4. abc vs def, n=0: %d\n", ft_strncmp("abc", "def", 0));
                                                        // Debe dar 0
    // Caso 5: n mayor que la longitud de ambas
    printf("5. abc vs abc, n=5: %d\n", ft_strncmp("abc", "abc", 5));
                                                        // Debe dar 0
    // Caso 6: Diferencias justo en el carácter 'n'
    printf("6. abc vs abx, n=2: %d\n", ft_strncmp("abc", "abx", 2));
                                                        // Debe dar 0
    return 0;
}*/
