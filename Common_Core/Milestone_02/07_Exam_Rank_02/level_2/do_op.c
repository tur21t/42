/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam02_tmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:30:36 by dmtur             #+#    #+#             */
/*   Updated: 2026/01/20 21:19:32 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int		n1 = atoi(av[1]);
	int		n2 = atoi(av[3]);;
	char	sign = av[2][0];

	if (ac == 4)
	{
		if (sign == '+')
			printf("%i", n1+n2);
		if (sign == '-')
			printf("%i", n1-n2);
		if (sign == '*')
			printf("%i", n1*n2);
		if (sign == '/')
			printf("%i", n1/n2);
		if (sign == '%')
			printf("%i", n1%n2);
	}
	printf("\n");
	return (0);
}
