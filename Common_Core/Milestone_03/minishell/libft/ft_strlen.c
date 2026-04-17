/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 14:01:43 by dfrincu           #+#    #+#             */
/*   Updated: 2025/05/16 15:18:15 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
/*#include <stdio.h>
int main(void)
{
    printf("Longitud de 'Hola': %zu\n", ft_strlen("Hola"));
    printf("Longitud de '': %zu\n", ft_strlen(""));
    printf("Longitud de 'Hola mundo!': %zu\n", ft_strlen("Hola mundo!"));
    return 0;
}*/
