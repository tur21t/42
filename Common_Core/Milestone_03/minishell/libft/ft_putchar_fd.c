/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:50:06 by dfrincu           #+#    #+#             */
/*   Updated: 2025/05/26 10:55:30 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
	return (1);
}
/*int	main(void)
{
	ft_putchar_fd('A', 1);
	return (0);
}*/
