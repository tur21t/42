/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 21:26:50 by dmtur             #+#    #+#             */
/*   Updated: 2025/06/08 20:36:26 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	int		i;
	char	*copy;

	i = 0;
	while (src[i] != '\0')
		i++;
	copy = malloc((i + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/*
#include <stdio.h>

int	main(void)
{
    char	*original = "Om Tare Tuttare Ture Svaha";
    char	*duplicate = ft_strdup(original);

    if (duplicate == NULL)
    {
        printf("Memory allocation failed!\n");
        return (1);
    }

    printf("Original:  %s\n", original);
    printf("Duplicate: %s\n", duplicate);

    free(duplicate);

    return (0);
}*/
