/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:45:58 by dmtur             #+#    #+#             */
/*   Updated: 2025/10/15 14:06:59 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_ptr_recursive(unsigned long n, size_t *counter)
{
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n >= 16)
		ft_put_ptr_recursive(n / 16, counter);
	ft_putchar_pf(symbols[n % 16], counter);
}

void	ft_put_ptr_pf(void *ptr, size_t *counter)
{
	unsigned long	n;

	if (ptr == NULL)
	{
		ft_putstr_pf("(nil)", counter);
		return ;
	}
	n = (unsigned long)ptr;
	ft_putstr_pf("0x", counter);
	ft_put_ptr_recursive(n, counter);
}
