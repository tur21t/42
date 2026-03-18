/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_pf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:05:32 by dmtur             #+#    #+#             */
/*   Updated: 2025/10/12 19:06:34 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_unsigned_pf(unsigned int n, size_t *counter)
{
	if (n >= 10)
		ft_put_unsigned_pf(n / 10, counter);
	ft_putchar_pf((n % 10) + '0', counter);
}
