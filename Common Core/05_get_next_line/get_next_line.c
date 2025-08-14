/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:42:58 by dmtur             #+#    #+#             */
/*   Updated: 2025/08/12 19:13:56 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

#include <fcntl.h>

int	main(void)
{
	int	fd;
	char		buffer[5];
	ssize_t	bytes_read;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	bytes_read = read(fd, buffer, 5);
	if (bytes_read > 0)
       		write(1, buffer, bytes_read);
	close(fd);

	ft_putstr("\n\n SARVA MANGALAM\n\n\n");
	return (0);
}
