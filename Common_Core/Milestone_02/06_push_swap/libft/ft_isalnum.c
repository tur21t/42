/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:43:43 by dmtur             #+#    #+#             */
/*   Updated: 2025/06/06 22:07:21 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char test_chars[] = {'t', 'u', 'R', '2', '1', 't', '\n', '*', '0'};
	int length = sizeof(test_chars) / sizeof(test_chars[0]);
	int i;

	for (i = 0; i < length; i++)
	{
		if (ft_isalnum(test_chars[i]))
			printf("'%c' is alphanumeric.\n", test_chars[i]);
		else
			printf("'%c' is NOT alphanumeric.\n", test_chars[i]);
	}
	return (0);
}*/
