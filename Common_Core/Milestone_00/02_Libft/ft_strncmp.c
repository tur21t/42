/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:04:39 by dmtur             #+#    #+#             */
/*   Updated: 2025/06/11 15:35:25 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*a = "Namo Tara";
	const char	*b = "Namo Sarasvati";
	size_t	n1 = 4;
	size_t n2 = 7;
	
	printf("Compare first %zu characters of \"%s\" and \"%s\":\n", n1, a, b);
	printf("ft_strncmp result : %d\n", ft_strncmp(a, b, n1));
	printf("strncmp result    : %d\n", strncmp(a, b, n1));
        printf("Compare first %zu characters of \"%s\" and \"%s\":\n", n2, a, b);
        printf("ft_strncmp result : %d\n", ft_strncmp(a, b, n2));
        printf("strncmp result    : %d\n", strncmp(a, b, n2));

	
	return (0);
}*/
