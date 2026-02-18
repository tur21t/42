/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam02_tmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:30:36 by dmtur             #+#    #+#             */
/*   Updated: 2026/01/26 17:25:28 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include <unistd.h>
#include <stdio.h>


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
	unsigned char	c1 = 'A';
	unsigned char	c2 = 'B';

	printf("test value: %c(%u)\n", c1, c1);
	print_bits(c1);
	write(1, "_A\n", 3);
	printf("test value: %c(%u)\n", c2, c2);
	print_bits(c2);
	write(1, "_t\n", 3);
	return (0);
}
