/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam02_tmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:30:36 by dmtur             #+#    #+#             */
/*   Updated: 2026/01/21 21:19:12 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(char *str1, char *str2)
{
	int	i  = 0;
	int	 j;

	while (str1[i])
	{
		j = 0;
		while (str2[j])
		{
			if (str1[i] == str2[j])
				return (i);
			j++;
		}
		i++;	
	}
	return (i);
}

int	main(int ac, char **av)
{
	int	i = 1;
	if (ac == 3)
	{	
			printf("strcspn result: %zu", strcspn(av[1], av[2]));
			printf("\n");
			printf("ft_strcspn result: %zu", ft_strcspn(av[1], av[2]));
			i++;
	}
	printf("\n");
	return (0);
}
