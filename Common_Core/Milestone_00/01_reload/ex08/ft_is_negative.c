/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:47:01 by dmtur             #+#    #+#             */
/*   Updated: 2025/05/02 18:26:36 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_is_negative(int n)
{
	char	c;

	c = 'N';
	if (n >= 0)
	{
		c = 'P';
	}
	ft_putchar(c);
}
/*
#include <unistd.h>

int	main(void)
{
	write(1, "Test 1: n = 3 : ", 16);
	ft_is_negative(3);
	write(1, "Test 2: n = -7 : ", 17);
	ft_is_negative(-7);
	write(1, "Test 3: n = 0 : ", 16);
	ft_is_negative(0);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
	write(1, "\n", 1);
}*/
