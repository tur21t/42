/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:40:33 by dmtur             #+#    #+#             */
/*   Updated: 2025/10/15 13:34:58 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_hex_pf(unsigned int n, size_t *counter, int uppercase)
{
	char	*symbols;

	if (uppercase)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (n >= 16)
		ft_put_hex_pf(n / 16, counter, uppercase);
	ft_putchar_pf(symbols[n % 16], counter);
}
