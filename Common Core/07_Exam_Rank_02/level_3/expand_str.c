/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam02_tmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:30:36 by dmtur             #+#    #+#             */
/*   Updated: 2026/01/28 18:12:46 by dmtur            ###   ########.fr       */
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

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	is_not_space = 1;
		int	first_word_printed = 0;
		int	i = 0;
		while (av[1][i])		
		{
			if (av[1][i] == ' ' || (av[1][i] >= 9 && av[1][i] <= 13))
			{
				is_not_space = 0;			
			} else 
			{
				if (is_not_space == 0 && first_word_printed == 1)
					write(1, "   ", 3);
				is_not_space = 1;
				first_word_printed = 1;
				write(1, &av[1][i], 1);
			}

			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
