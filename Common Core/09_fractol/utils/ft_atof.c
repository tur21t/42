/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:55:38 by dmtur             #+#    #+#             */
/*   Updated: 2026/02/04 20:55:45 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(char *s)
{
	double	result;
	double	sign;
	double	div;

	result = 0.0;
	sign = 1.0;
	div = 1.0;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1.0;
	while (*s >= '0' && *s <= '9')
		result = result * 10.0 + (*s++ - '0');
	if (*s == '.')
	{
		s++;
		while (*s >= '0' && *s <= '9')
		{
			div *= 10.0;
			result += (*s++ - '0') / div;
		}
	}
	return (result * sign);
}
