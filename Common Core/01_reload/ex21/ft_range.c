/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:31:03 by dmtur             #+#    #+#             */
/*   Updated: 2025/05/09 17:03:20 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	size;
	int	i;

	if (min >= max)
		return (NULL);
	size = max - min;
	arr = malloc(sizeof(int) * size);
	i = 0;
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}
/*
#include <stdio.h>

int     main(int argc, char **argv)
{
        int     min;
        int     max;
        int     *range;
        int     i;

        if (argc != 3)
        {
                printf("Usage: %s min max\n", argv[0]);
                return (1);
        }
        min = atoi(argv[1]);
        max = atoi(argv[2]);

        range = ft_range(min, max);
        if (range == NULL)
        {
                printf("NULL\n");
                return (1);
        }
        i = 0;
        while (i < max - min)
        {
                printf("%d\n", range[i]);
                i++;
        }
        free(range);
        return (0);
}*/
