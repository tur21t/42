/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:57:43 by dfrincu           #+#    #+#             */
/*   Updated: 2025/05/26 11:05:54 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	if (!s)
		return (write(fd, "(null)", 6));
	len = 0;
	while (s[len])
		len++;
	return (write(fd, s, len));
}
/*int	main()
{
	ft_putstr_fd("Pepito", 1);
	return (0);
}*/
