/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam02_tmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:30:36 by dmtur             #+#    #+#             */
/*   Updated: 2026/01/30 13:41:38 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	i = 2;
	int	flag_first = 1;
	
	if (ac != 2)
	{
		printf("\n");
		return (0);
	}

	int	n = atoi(av[1]);

	if (n == 1)
	{
		printf("1\n");
		return (0);
	}
	
	if (ac == 2 && n > 0)
	{
		while (n > 1)
		{
			if ((n % i) == 0)
			{
				if (!flag_first)
					printf("*");

				printf("%d", i);
				n = n / i;
				flag_first = 0;
			}
			else
			{
				i++;
			}
		}
	}
	printf("\n");
	return (0);
}
