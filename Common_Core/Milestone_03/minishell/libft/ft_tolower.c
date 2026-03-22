/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:41:57 by dfrincu           #+#    #+#             */
/*   Updated: 2025/05/16 16:36:29 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}
/*#include <stdio.h>
int     main ()
{
    printf("ft_tolower('A') = %c\n", ft_tolower('A'));   // Debe mostrar 'a'
    printf("ft_tolower('Z') = %c\n", ft_tolower('Z'));   // Debe mostrar 'z'
    printf("ft_tolower('a') = %c\n", ft_tolower('a'));   // Debe mostrar 'a'
    printf("ft_tolower('!') = %c\n", ft_tolower('!'));   // Debe mostrar '!'
    printf("ft_tolower(0) = %d\n", ft_tolower(0));       // Debe mostrar 0

    // Caso adicional para verificar números dentro del rango
    printf("ft_tolower(68) = %c\n", ft_tolower(68));   // 'D' → 'd'

    return (0);
}*/
