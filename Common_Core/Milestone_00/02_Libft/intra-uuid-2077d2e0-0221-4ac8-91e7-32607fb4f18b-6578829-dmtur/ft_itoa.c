/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 19:13:32 by dmtur             #+#    #+#             */
/*   Updated: 2025/06/15 21:14:30 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_intlen(int n)
{
	int	len;

	len = (n <= 0);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	num;
	int		len;
	char	*str;

	num = n;
	len = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	if (num == 0)
		str[0] = '0';
	while (num)
	{
		str[len--] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char *s;

	s = ft_itoa(21);
	printf("21: %s\n", s);
	free(s);

	s = ft_itoa(-108);
	printf("-108: %s\n", s);
	free(s);

	s = ft_itoa(0);
	printf("0: %s\n", s);
	free(s);

	s = ft_itoa(-2147483648);
	printf("-2147483648: %s\n", s);
	free(s);

	s = ft_itoa(2147483647);
	printf("2147483647: %s\n", s);
	free(s);

	return (0);
}*/
