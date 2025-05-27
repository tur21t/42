/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:00:29 by dmtur             #+#    #+#             */
/*   Updated: 2025/03/06 20:08:05 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}
/*
#include <unistd.h>

void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	main(void)
{
	ft_putnbr(ft_iterative_power(2, 3));
	write(1, "\n", 1);
	ft_putnbr(ft_iterative_power(5, 0));
	write(1, "\n", 1);
	ft_putnbr(ft_iterative_power(0, 0));
	write(1, "\n", 1);
	ft_putnbr(ft_iterative_power(2, -3));
	write(1, "\n", 1);
	return (0);
}*/
