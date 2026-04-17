/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:09:32 by dmtur             #+#    #+#             */
/*   Updated: 2025/03/06 20:17:14 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	return (nb * ft_recursive_power(nb, power - 1));
}
/*
#include <unistd.h>

void	ft_putnbr(int n)
{
	char	c;

	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	main(void)
{
	ft_putnbr(ft_recursive_power(2, 3));
	write(1, "\n", 1);
	ft_putnbr(ft_recursive_power(5, 0));
	write(1, "\n", 1);
	ft_putnbr(ft_recursive_power(0, 0));
	write(1, "\n", 1);
	ft_putnbr(ft_recursive_power(2, -3));
	write(1, "\n", 1);
	return (0);
}*/
