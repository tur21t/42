/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:48:00 by dmtur             #+#    #+#             */
/*   Updated: 2025/02/24 20:06:57 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}
/*
int	main(void)
{
	char	a;
	char	b;
	int	x;
	int	y;

	x = 1;
	y = 2;
	ft_swap(&x, &y);
	a = x + '0';
	b = y + '0';
	write(1, "a: ", 3);
	write(1, &a, 1);
	write(1, "\n", 1);
	write(1, "b: ", 3);
	write(1, &b, 1);
	write(1, "\n", 1);
	return (0);
}*/
