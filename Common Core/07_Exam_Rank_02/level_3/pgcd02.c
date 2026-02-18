/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam02_tmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:30:36 by dmtur             #+#    #+#             */
/*   Updated: 2026/01/29 23:52:45 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int	nbr1 = atoi(av[1]);
		int	nbr2 = atoi(av[2]);

		while (nbr1 != nbr2)
		{
			if (nbr1 > nbr2)
			{
				nbr1 = nbr1 - nbr2;
			} else
			{
				nbr2 = nbr2 - nbr1;
			}
		}
		printf("%d", nbr1);
	}
	printf("\n");
	return (0);
}
