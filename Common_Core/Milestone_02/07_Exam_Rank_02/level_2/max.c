/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:19:49 by dmtur             #+#    #+#             */
/*   Updated: 2025/11/21 18:52:09 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	max(int* tab, unsigned int len)
{
	unsigned int	i;
	int	result;
	
	i = 1;
	result = tab[0];
	if (len > 0)
	{
		while(i < len)
		{
			if(tab[i] > result)
				result = tab[i];
			i++;
		}
		return (result);

	}
	return (0);
}

#include <stdio.h>

int	main(void)
{
	int tab[] = {7, 5, 21, 9};
	printf("%d", max(tab, 4));
	return (1);
}
