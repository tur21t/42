/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:55:36 by dfrincu           #+#    #+#             */
/*   Updated: 2025/05/27 13:13:12 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}
/*#include <stdio.h>
int main(void)
{
    const char *str = "Hola mundo";
    char c1 = 'm';
    char c2 = 'z';
    char c3 = '\0';

    char *result1 = ft_strchr(str, c1);
    char *result2 = ft_strchr(str, c2);
    char *result3 = ft_strchr(str, c3);

    if (result1)
        printf("Encontrado '%c' en: %s\n", c1, result1);
    else
        printf("'%c' no encontrado.\n", c1);

    if (result2)
        printf("Encontrado '%c' en: %s\n", c2, result2);
    else
        printf("'%c' no encontrado.\n", c2);

    if (result3)
        printf("Encontrado carácter nulo al final: %p\n", (void *)result3);
    else
        printf("Carácter nulo no encontrado.\n");

    return 0;
}*/
