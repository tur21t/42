/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 21:02:48 by dmtur             #+#    #+#             */
/*   Updated: 2025/06/12 21:18:35 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				i;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return ((p1[i] - p2[i]));
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str1[] = "Hello World_RD_13";
	char	str2[] = "Hello World_RD_13";
	char	str3[] = "Hello World_RD_69";
	size_t	n = 17;
	int	res1 = ft_memcmp(str1, str2, n);
	int	res2 = memcmp(str1, str3, n);
	
	printf("ft_memcmp(str1, str2, %zu) = %d\n", n, res1);
	printf("memcmp(str1, str3, %zu) = %d\n", n, res2);
	
	if (res1 == 0)
		printf("ft_memcmp: str1 and str2 are equal\n");
       else
	       printf("ft_memcmp: str1 and str2 differ\n");
       if (res2 == 0)
	       printf("memcmp: str1 and str3 are equal\n");
       else
	       printf("memcmp: str1 and str3 differ\n");
       return (0);
}*/
