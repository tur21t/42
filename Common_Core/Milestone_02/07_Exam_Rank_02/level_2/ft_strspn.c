/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam02_tmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:30:36 by dmtur             #+#    #+#             */
/*   Updated: 2026/01/22 23:04:45 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include <string.h>
#include <stdio.h>

size_t	ft_strspn (const char *s, const char *accept)
{
	size_t	i = 0;
	size_t	j;
	int	found;

	while (s[i])
	{
		j = 0;
		found = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
			{
				found = 1;
				break;
			}
	
			j++;
	
		}
		if (found == 0)
			return (i);
		i++;
	}	
	return (i);
}

int	main(int ac, char **av)
{
	int	i = 1;
	if (ac == 3)
	{	
			printf("strspn result: %zu", strspn(av[1], av[2]));
			printf("\n");
			printf("ft_strspn result: %zu", ft_strspn(av[1], av[2]));
			i++;
	}
	printf("\n");
	return (0);
}
