/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:10:17 by dfrincu           #+#    #+#             */
/*   Updated: 2025/05/26 11:57:50 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putnbr_fd(int n, int fd)
{
	int		count;
	char	c;

	count = 0;
	if (n == -2147483648)
	{
		count += write(fd, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count += write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	count += write(fd, &c, 1);
	return (count);
}
/*int main()
{
    ft_putnbr_fd(42, 1);        // Debería imprimir "42"
    write(1, "\n", 1);    // Salto de línea
    ft_putnbr_fd(-2147483648, 1); // Debería imprimir "-2147483648"
    write(1, "\n", 1);    // Salto de línea
    ft_putnbr_fd(0, 1);         // Debería imprimir "0"
    write(1, "\n", 1);    // Salto de línea
    return 0;
}*/
