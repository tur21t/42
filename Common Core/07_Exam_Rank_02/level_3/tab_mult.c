/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam02_tmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:30:36 by dmtur             #+#    #+#             */
/*   Updated: 2026/01/29 22:46:44 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_atoi(char *str)
{
	int	i = 0; 
	int	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - '0';
		i++;		
	}
	return (result);
}

void	putnbr(int n)
{
	if (n >= 10)
		putnbr(n/10);
	char digit = n % 10 + '0';

	write(1, &digit, 1);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		int	i = 1;

		while (i <= 9)
		{
			int	n = ft_atoi(av[1]);

			putnbr(i);
			write(1, " x ", 3);
			putnbr(n);
			write(1, " = ", 3);
			putnbr(i*n);
			write(1, "\n", 1);
			i++;
		}
	} else
	{
		write(1, "\n", 1);
	}
	return (0);
}
