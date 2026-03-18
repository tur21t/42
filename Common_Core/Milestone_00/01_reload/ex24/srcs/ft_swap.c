/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:22:15 by dmtur             #+#    #+#             */
/*   Updated: 2025/05/03 15:31:06 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}
/*
#include <stdio.h>

void	ft_swap(int *a, int *b);

int	main(void)
{
	int x = 5;
	int y = 9;

	printf("Before swap: x = %d, y = %d\n", x, y);
	ft_swap(&x, &y);
	printf("After swap:  x = %d, y = %d\n", x, y);
	return (0);
}*/
