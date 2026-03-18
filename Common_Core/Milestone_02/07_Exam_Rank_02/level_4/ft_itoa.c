/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 22:28:44 by dmtur             #+#    #+#             */
/*   Updated: 2026/02/27 23:01:45 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	long	n;
	int	len;
	char	*str;

	n = nbr;
	len = 0;

	if (n <= 0)
		len = 1;
	while (n > 0)
	{
		len++;
		n = n / 10;
	}

	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';

	n = nbr;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	
	}
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
--------------------------------------------------------------------------------
char	*ft_itoa(int nbr)
{
	long	n;
	int	len;
	char	*str;

	n = nbr;
	len = 0;

	if (n <= 0)
		len = 1;
	while (n > 0)
	{
		len++;
		n = n / 10;
	}

	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';

	n = nbr;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	
	}
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
*/
