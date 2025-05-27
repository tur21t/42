/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:39:59 by dmtur             #+#    #+#             */
/*   Updated: 2025/03/06 19:58:11 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb < 0)
		return (0);
	while (nb > 1)
	{
		result *= nb;
		nb--;
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
	ft_putnbr(ft_iterative_factorial(5));
	write(1, "\n", 1);
	ft_putnbr(ft_iterative_factorial(0));
	write(1, "\n", 1);
	ft_putnbr(ft_iterative_factorial(-3));
	write(1, "\n", 1);
	return (0);
}*/
