/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfhelp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 11:47:30 by dfrincu           #+#    #+#             */
/*   Updated: 2025/06/19 10:48:01 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	with_char(int c)
{
	return (ft_putchar_fd(c, 1));
}

int	with_str(char *s)
{
	if (!s)
		return (ft_putstr_fd("(null)", 1));
	return (ft_putstr_fd(s, 1));
}

int	with_int(int n)
{
	return (ft_putnbr_fd(n, 1));
}

int	with_unsigned(unsigned int n)
{
	if (n >= 10)
		return (with_unsigned(n / 10) + ft_putchar_fd((n % 10) + '0', 1));
	return (ft_putchar_fd(n + '0', 1));
}

int	with_hex(unsigned int n, int uppercase)
{
	char	*base;
	int		count;

	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += with_hex(n / 16, uppercase);
	count += ft_putchar_fd(base[n % 16], 1);
	return (count);
}
