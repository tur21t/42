/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:30:36 by dmtur             #+#    #+#             */
/*   Updated: 2026/01/18 21:37:45 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int ac, char **av)
{
	int		i;
	char	c;
	if (ac == 2)
	{
		i = 0;
	
	
		while (av[1][i])
		{
			c = av[1][i];
			if (c >= 'a' && c <= 'z')
			{
				if (c > 'm')      // 'n'..'z' wrap around
					c -= 13;
				else              // 'a'..'m' shift forward
					c += 13;
			}
			else if (c >= 'A' && c <= 'Z')
			{
				if (c > 'M')      // 'N'..'Z' wrap around
					c -= 13;
				else              // 'A'..'M' shift forward
					c += 13;
			}
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
