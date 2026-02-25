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



int	main(int ac, char **av)
{
	unsigned char	c = 't';

	printf("test value: %c(%u)\n", c, c);
	//...
	write(1, "\n", 1);
	return (0);
}

/*

Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>

*/
