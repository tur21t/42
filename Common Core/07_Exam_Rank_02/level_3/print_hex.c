/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam02_tmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:30:36 by dmtur             #+#    #+#             */
/*   Updated: 2026/01/30 01:26:20 by dmtur            ###   ########.fr       */
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
		result = result * 10 +(str[i] - '0');
		i++;
	}
	return result;
}

void puthex(int n)
{
	char *digits = "0123456789abcdef";
	char c;
	if (n >= 16)
		puthex(n / 16);
	c = digits[n%16];
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
	
		puthex(ft_atoi(av[1]));

	}
	write(1, "\n", 1);
	return (0);
}
