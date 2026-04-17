/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 22:44:06 by dmtur             #+#    #+#             */
/*   Updated: 2025/06/13 19:48:23 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t			total;
	size_t			i;
	unsigned char	*ptr;

	total = count * size;
	ptr = (unsigned char *)malloc(total);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	size_t	n = 21;
	int	*i = (int *)ft_calloc(n, sizeof(int));
	if (!i)
	{
		printf("Allocation failed\n");
		return (1);
	}

	for (size_t j = 0; j < n; j++)
		printf("i[%zu] = %d\n", j, i[j]);
	free(i);
	return (0);
}*/
