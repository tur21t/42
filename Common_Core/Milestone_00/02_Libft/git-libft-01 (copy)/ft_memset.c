/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:22:45 by dmtur             #+#    #+#             */
/*   Updated: 2025/06/06 21:59:26 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    char buffer1[20] = "Hello, world!";
    char buffer2[20] = "Hello, world!";

    ft_memset(buffer1 + 7, 't', 5);

    memset(buffer2 + 7, 't', 5);

    printf("ft_memset : %s\n", buffer1);
    printf("memset: %s\n", buffer2);

    return (0);
}*/
