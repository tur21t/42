/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam02_tmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:30:36 by dmtur             #+#    #+#             */
/*   Updated: 2026/01/21 18:08:55 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	i  = 0;
	int	sign = 1;
	int	result = 0;

	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + str[i] - 48;
		i++;	
	}
	return (result * sign);
}

int	main(int ac, char **av)
{
	int	i = 1;
	if (ac > 1)
	{	
		while (i < ac)
		{
			printf("ft_atoi result: %i", ft_atoi(av[i]));
			printf("\n");
			printf("atoi result: %i", atoi(av[i]));
			i++;
		}
	}
	printf("\n");
	return (0);
}
