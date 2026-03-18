/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam02_tmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:30:36 by dmtur             #+#    #+#             */
/*   Updated: 2026/01/22 17:26:23 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include <string.h>
#include <stdio.h>

char	*ft_strpbrk(const char *str1, const char *str2)
{
	int	i  = 0;
	int	 j;

	while (str1[i])
	{
		j = 0;
		while (str2[j])
		{
			if (str1[i] == str2[j])
				return ((char  *)&str1[i]);
			j++;
		}
		i++;	
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	i = 1;
	if (ac == 3)
	{	
			printf("strpbrk result: %s", strpbrk(av[1], av[2]));
			printf("\n");
			printf("ft_strpbrk result: %s", ft_strpbrk(av[1], av[2]));
			i++;
	}
	printf("\n");
	return (0);
}
