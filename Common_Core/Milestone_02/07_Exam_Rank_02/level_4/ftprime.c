/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam02_tmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:30:36 by dmtur             #+#    #+#             */
/*   Updated: 2026/01/20 19:20:19 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	n = atoi(av[1]);
	int	first = 1;
	int	i = 2;

	if (ac != 2)
	{
		printf("\n");
		return (0);
	}


	if (n == 1)
	{
		printf("1\n");
		return (0);
	}


	while (i <= n)
	{
		while (n % i == 0)
		{
			if (!first)
				printf("*");
			printf("%d", i);
			first = 0;
			n /= i;	
		}
		i++;
	}
	printf("\n");
	return (0);
}
