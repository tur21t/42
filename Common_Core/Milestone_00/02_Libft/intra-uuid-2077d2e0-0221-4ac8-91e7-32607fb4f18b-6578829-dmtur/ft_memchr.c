/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:45:30 by dmtur             #+#    #+#             */
/*   Updated: 2025/06/12 20:58:56 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

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
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char  data[] = "Om Tare Tuttare Ture Svaha";
	int         ch = 'T';
	size_t      len = sizeof(data);
    
	void	*result1 = ft_memchr(data, ch, len);
	void	*result2 = memchr(data, ch, len);

	printf("Original data: %s\n", data);
	printf("Character to find: '%c'\n", ch);

	printf("ft_memchr result: %s\n", result1 ? (char *)result1 : "NULL");
	printf("memchr result   : %s\n", result2 ? (char *)result2 : "NULL");

	return (0);
}*/
