/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 22:28:46 by dmtur             #+#    #+#             */
/*   Updated: 2025/10/12 17:06:04 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_pf(int n, size_t *counter)
{
	long	num;
	char	digit;

	num = n;
	if (n < 0)
	{
		ft_putchar_pf('-', counter);
		num = -num;
	}
	if (num >= 10)
		ft_putnbr_pf(num / 10, counter);
	digit = (num % 10) + '0';
	ft_putchar_pf(digit, counter);
}
