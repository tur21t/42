/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 22:19:54 by dmtur             #+#    #+#             */
/*   Updated: 2025/06/11 14:53:17 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strrchr(const char *str, int ch)
{
	const char	*last;

	last = NULL;
	while (*str)
	{
		if (*str == (char)ch)
			last = str;
		str++;
	}
	if ((char)ch == '\0')
		return ((char *)str);
	return ((char *)last);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*str = "Om Tare Tuttare Ture Svaha";
	int	ch = 'T';

	printf("Original string : %s\n", str);
	printf("Character to find (last occurrence): '%c'\n", ch);
	printf("ft_strrchr result: %s\n", ft_strrchr(str, ch));
	printf("strrchr result   : %s\n", strrchr(str, ch));
	return (0);
}*/
