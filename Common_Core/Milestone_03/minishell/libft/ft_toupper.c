/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 14:20:47 by dfrincu           #+#    #+#             */
/*   Updated: 2025/05/16 16:34:22 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c = c - 32;
	return (c);
}

/*#include <stdio.h>
int	main ()
{
    printf("ft_toupper('a') = %c\n", ft_toupper('a'));   // Debe mostrar 'A'
    printf("ft_toupper('z') = %c\n", ft_toupper('z'));   // Debe mostrar 'Z'
    printf("ft_toupper('A') = %c\n", ft_toupper('A'));   // Debe mostrar 'A'
    printf("ft_toupper('!') = %c\n", ft_toupper('!'));   // Debe mostrar '!'
    printf("ft_toupper(0) = %d\n", ft_toupper(0));       // Debe mostrar 0

    // Caso adicional para verificar números dentro del rango
    printf("ft_toupper(100) = %c\n", ft_toupper(100));   // 'd' → 'D'

    return (0);
}*/
