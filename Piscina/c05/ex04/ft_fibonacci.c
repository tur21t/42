/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:19:08 by dmtur             #+#    #+#             */
/*   Updated: 2025/03/06 20:36:35 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
/*
#include <unistd.h>

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	main(void)
{
	int	result1;
	int	result2;

	result1 = ft_fibonacci(7);
	result2 = ft_fibonacci(21);
	write(1, "Fibonacci result1: ", 19);
	ft_putnbr(result1);
	write(1, "\n", 1);
	write(1, "Fibonacci result2: ", 19);
	ft_putnbr(result2);
	write(1, "\n", 1);
	return (0);
}*/
