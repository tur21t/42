/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:34:29 by dfrincu           #+#    #+#             */
/*   Updated: 2025/05/16 11:57:57 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t				i;

	ptr = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
/*#include <stdio.h>
int main()
{
    // Caso válido
    printf("%s\n", (char *)ft_memchr("hello", 'e', 5));  // → "ello"

    // Caso válido con n == 0 (no accede a memoria)
    printf("%s\n", (char *)ft_memchr(NULL, 'e', 0));     // → (null)

    return (0);
}*/
