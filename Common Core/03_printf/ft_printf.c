/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 19:13:31 by dmtur             #+#    #+#             */
/*   Updated: 2025/07/28 21:42:20 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_format(char specifier, va_list args)
{
	int		count;
	char	c;

	count = 0;
	if (specifier == 'c')
	{
		c = va_arg(args, int);
		ft_putchar_fd(c, 1);
		count++;
	}
	else if (specifier == '%')
	{
		ft_putchar_fd('%', 1);
		count++;
	}
	return (count);
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

		//add a check here
		if (format[i] == '%')
		{
			i++;
			count += handle_format(format[i], args);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	ft_printf("OmTareTuttareTureSvaha\n");
	ft_printf("Letter: %c\n", 'A');
	ft_printf("Percent: %%\n");
	return (0);
}
