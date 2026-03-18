/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam02_tmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:30:36 by dmtur             #+#    #+#             */
/*   Updated: 2026/01/21 20:52:02 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include <string.h>
#include <stdio.h>

int	ft_strcmp(char *str1, char *str2)
{
	int	i  = 0;

	while (str1[i] && str2[i] && str1[i] == str2[i])
	{
		i++;	
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

int	main(int ac, char **av)
{
	int	i = 1;
	if (ac == 3)
	{	
			printf("strcmp result: %i", strcmp(av[1], av[2]));
			printf("\n");
			printf("ft_strcmp result: %i", ft_strcmp(av[1], av[2]));
			i++;
	}
	printf("\n");
	return (0);
}
