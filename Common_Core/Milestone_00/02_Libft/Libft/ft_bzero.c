/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:59:24 by dmtur             #+#    #+#             */
/*   Updated: 2025/06/07 20:17:04 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char test1[10] = "123456789";
    char test2[10] = "123456789";

    ft_bzero(test1, 5);
    bzero(test2, 5);

    printf("ft_bzero result: ");
    for (int i = 0; i < 10; i++)
        printf("%02x ", (unsigned char)test1[i]);
    printf("\n");

    printf("bzero result   : ");
    for (int i = 0; i < 10; i++)
        printf("%02x ", (unsigned char)test2[i]);
    printf("\n");

    if (memcmp(test1, test2, 10) == 0)
        printf("Success: ft_bzero matches bzero.\n");
    else
        printf("Mismatch found.\n");

    return 0;
}*/
