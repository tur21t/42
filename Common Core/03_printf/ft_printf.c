/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 19:13:31 by dmtur             #+#    #+#             */
/*   Updated: 2025/10/15 15:42:25 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_format(va_list va, char *specifier, size_t *counter)
{
	if (*specifier == 'c')
		ft_putchar_pf(va_arg(va, int), counter);
	else if (*specifier == 'd' || *specifier == 'i')
		ft_putnbr_pf(va_arg(va, int), counter);
	else if (*specifier == 'p')
		ft_put_ptr_pf(va_arg(va, void *), counter);
	else if (*specifier == 's')
		ft_putstr_pf(va_arg(va, char *), counter);
	else if (*specifier == 'u')
		ft_put_unsigned_pf(va_arg(va, unsigned int), counter);
	else if (*specifier == 'x')
		ft_put_hex_pf(va_arg(va, unsigned int), counter, 0);
	else if (*specifier == 'X')
		ft_put_hex_pf(va_arg(va, unsigned int), counter, 1);
	else if (*specifier == '%')
		ft_putchar_pf('%', counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	va;
	size_t	count;

	if (format == NULL)
		return (0);
	count = 0;
	va_start(va, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				handle_format(va, (char *)format, &count);
		}
		else
			ft_putchar_pf(*format, &count);
		format++;
	}
	va_end(va);
	return (count);
}
/*
#include <stdio.h>
int	main(void)
{
	int		ret_ft;
	int		ret_orig;

	ft_printf("/n--- basic test ---\n");
	ft_printf("ft_printf: ");
	ret_ft = ft_printf("OmTareTuttareTureSvaha\n");
	printf("printf: ");
	ret_orig = printf("OmTareTuttareTureSvaha\n");
	printf("Return values → ft_printf: %d | printf: %d\n", ret_ft, ret_orig);

	ft_printf("\n--- %%c test ---\n");
	ft_printf("ft_printf: ");
	ret_ft = ft_printf("Letter: %c %c\n", 'A', 116);
	printf("printf: ");
	ret_orig = printf("Letter: %c %c\n", 'A', 116);
	printf("Return values → ft_printf: %d | printf: %d\n", ret_ft, ret_orig);
	
	ft_printf("\n--- %%percent test ---\n");
	ft_printf("ft_printf: ");
	ret_ft = ft_printf("Percent: %%\n");
	printf("printf: ");
	ret_orig = printf("Percent: %%\n");
	printf("Return values → ft_printf: %d | printf: %d\n", ret_ft, ret_orig);

	ft_printf("\n--- %%s test ---\n");
	ft_printf("ft_printf: ");
        ret_ft = ft_printf("Hello World: %s\n", "RD_13");
	printf("printf: ");
	ret_orig = printf("Hello World: %s\n", "RD_13");
	printf("Return values → ft_printf: %d | printf: %d\n", ret_ft, ret_orig);

	ft_printf("\n--- %%d and %%i test ---\n");
	ft_printf("ft_printf: ");
	ret_ft = ft_printf("Positive: %d, Negative: %d, Zero: %d\n", 108, -108, 0);
	printf("printf: ");
	ret_orig = printf("Positive: %d, Negative: %d, Zero: %d\n", 108, -108, 0);
	printf("Return values → ft_printf: %d | printf: %d\n", ret_ft, ret_orig);
        
	ft_printf("\n--- %%p tests ---\n");

	int	num = 42;
	void	*ptr = &num;
	void	*null_ptr = NULL;

	ft_printf("ft_printf: ");
	ret_ft = ft_printf("Pointer address: %p\n", ptr);
	printf("printf: ");
	ret_orig = printf("Pointer address: %p\n", ptr);
	printf("Return values → ft_printf: %d | printf: %d\n\n", ret_ft, ret_orig);

	ft_printf("ft_printf: ");
	ret_ft = ft_printf("NULL pointer: %p\n", null_ptr);
	printf("printf: ");
	ret_orig = printf("NULL pointer: %p\n", null_ptr);
	printf("Return values → ft_printf: %d | printf: %d\n\n", ret_ft, ret_orig);

	char	c = 'A';
	void	*ptr_char = &c;

	ft_printf("ft_printf: ");
	ret_ft = ft_printf("Char pointer: %p\n", ptr_char);
	printf("printf: ");
	ret_orig = printf("Char pointer: %p\n", ptr_char);
	printf("Return values → ft_printf: %d | printf: %d\n\n", ret_ft, ret_orig);
	
	ft_printf("\n--- %%x / %%X tests ---\n");
	ft_printf("ft_printf: ");
	ret_ft = ft_printf("Lowercase hex: %x\n", 255);
	printf("printf: ");
	ret_orig = printf("Lowercase hex: %x\n", 255);
	printf("Return values → ft_printf: %d | printf: %d\n\n", ret_ft, ret_orig);

	ft_printf("ft_printf: ");
	ret_ft = ft_printf("Uppercase hex: %X\n", 255);
	printf("printf: ");
	ret_orig = printf("Uppercase hex: %X\n", 255);
        printf("Ret. values → ft_printf: %d | printf: %d\n\n", ret_ft, ret_orig);
	
	ft_printf("ft_printf: ");
	ret_ft = ft_printf("Mix: %x %X %x %X\n", 0, 42, 255, 4095);
	printf("printf: ");
	ret_orig = printf("Mix: %x %X %x %X\n", 0, 42, 255, 4095);
	printf("Return values → ft_printf: %d | printf: %d\n\n", ret_ft, ret_orig);

	ft_printf("ft_printf: ");
	ret_ft = ft_printf("Big value: %x\n", 4294967295u);
	printf("printf: ");
	ret_orig = printf("Big value: %x\n", 4294967295u);
	printf("Return values → ft_printf: %d | printf: %d\n\n", ret_ft, ret_orig);
   
 	ft_printf("\n--- NULL test ---\n");
	char *null_str = NULL;
	ft_printf("ft_printf: ");
        ret_ft = ft_printf("Null test: %s\n", null_str);
	printf("printf: ");
	//ret_orig = printf("Null test: %s\n", NULL);
	ret_orig = printf("Null test: %s\n", null_str);
	printf("Return values → ft_printf: %d | printf: %d\n\n", ret_ft, ret_orig);

	ft_printf("\n--- %%u test ---\n");
	int		signed_num = -1;
	unsigned int	unsigned_num = 4294967295;
	ft_printf("ft_printf: ");
        ret_ft = ft_printf("signed -1 as %%u: %u\n", (unsigned int)signed_num);
	printf("printf: ");
	ret_orig = printf("signed -1 as %%u: %u\n", (unsigned int)signed_num);
	printf("Return values → ft_printf: %d | printf: %d\n", ret_ft, ret_orig);
	ft_printf("ft_printf: ");
        ret_ft = ft_printf("unsigned 4294967295 as %%u: %u\n", unsigned_num);
	printf("printf: ");
	ret_orig = printf("unsigned 4294967295 as %%u: %u\n", unsigned_num);
	printf("Return values → ft_printf: %d | printf: %d\n", ret_ft, ret_orig);
	return (0);
}*/
