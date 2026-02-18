/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:29:24 by dmtur             #+#    #+#             */
/*   Updated: 2025/11/18 19:48:11 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	int	i;
	int	n;

	i = 2;
	if (ac == 2)
	{
		n = atoi(av[1]);
		if (n == 1)
			printf("1");
		while (i <= n)
		{
			if (n % i == 0)
			{
				printf("%d", i);
				if (n != i)
					printf("*");
				n = n / i;
			}
			else
				i++;
		}
	}
	printf("\n");
	return (0);
}
