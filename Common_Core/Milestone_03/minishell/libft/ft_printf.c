/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:33:08 by dfrincu           #+#    #+#             */
/*   Updated: 2025/06/19 17:43:20 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	print_format(char spec, va_list args)
{
	if (spec == 'c')
		return (with_char(va_arg(args, int)));
	else if (spec == 's')
		return (with_str(va_arg(args, char *)));
	else if (spec == 'd' || spec == 'i')
		return (with_int(va_arg(args, int)));
	else if (spec == 'u')
		return (with_unsigned(va_arg(args, unsigned int)));
	else if (spec == 'x')
		return (with_hex(va_arg(args, unsigned int), 0));
	else if (spec == 'X')
		return (with_hex(va_arg(args, unsigned int), 1));
	else if (spec == 'p')
		return (with_ptr((unsigned long)va_arg(args, void *)));
	else if (spec == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += print_format(format[i], args);
		}
		else
		{
			count += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (count);
}

static int	print_ptr_hex(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr >= 16)
		count += print_ptr_hex(ptr / 16);
	count += ft_putchar_fd("0123456789abcdef"[ptr % 16], 1);
	return (count);
}

int	with_ptr(unsigned long ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr_fd("(nil)", 1));
	count = ft_putstr_fd("0x", 1);
	count += print_ptr_hex(ptr);
	return (count);
}
