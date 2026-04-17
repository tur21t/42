/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam02_tmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:30:36 by dmtur             #+#    #+#             */
/*   Updated: 2026/01/23 11:34:45 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include <unistd.h>
#include <stdlib.h>

int	is_power_of_2(unsigned int n)
{
	unsigned int num = 1;
	while (num < n)
		{
			num *= 2;
			if (num == n)
				return (1);
		}
	return (0);
}

int	main(int ac, char **av)
{
	//int	i = 0;

	if (ac == 2)
	{
		if (is_power_of_2((unsigned int)atoi(av[1])))
			write(1, "yes", 3);
		else 
			write(1, "no", 2);
	}
	write(1, "\n", 1);
	return (0);
}
