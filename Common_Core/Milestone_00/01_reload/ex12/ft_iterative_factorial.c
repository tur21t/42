/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 19:51:49 by dmtur             #+#    #+#             */
/*   Updated: 2025/05/05 20:57:53 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	num;
	int	i;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	i = 1;
	num = 1;
	while (i <= nb)
	{
		num = num * i;
		++i;
	}
	return (num);
}
/*
#include <stdio.h>

int	main(void)
{
	int i = 5;
	printf("%d! = %d\n", i, ft_iterative_factorial(i)); // Expected: 120
	return (0);
}*/
