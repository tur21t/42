/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam02_tmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:30:36 by dmtur             #+#    #+#             */
/*   Updated: 2026/01/27 18:17:59 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *c)
{
	int	i = 0;
	int	result;
	int	sign = 1;

	if (c[i] == ' ' || c[i] == '\t' || c[i] == '\r')
		i++;
	if (c[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (c[i])
	{
		result = result * 10 - '0';
		i++;
	}
	result *= sign;
	return (0);
}

void	putnbr(int n)
{
	if (n >= 10)
		putnbr(n/10);
	char	digit = n % 10 + '0';
	write(1, &digit, 1);
}

void	print_bits(unsigned char octet)
{
	unsigned int	n = 128;
		
	while (n > 0)
	{
		if (octet & n)
			write(1, "1", 1);
		else 
			write(1, "0", 1);
		n = n / 2;
	}
}

int	main()
{
	unsigned char	c = 't';

	printf("test value: %c(%u)\n", c, c);
	print_bits(c);
	write(1, "\n", 1);
	return (0);
}
