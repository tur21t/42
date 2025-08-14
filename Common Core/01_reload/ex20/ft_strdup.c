/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:37:20 by dmtur             #+#    #+#             */
/*   Updated: 2025/05/09 16:15:20 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		length;
	char	*copy;

	length = 0;
	while (src[length] != '\0')
		length++;
	copy = malloc((length + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	length = 0;
	while (src[length])
	{
		copy[length] = src[length];
		length++;
	}
	copy[length] = '\0';
	return (copy);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*original = "Om Tare Tuttare Ture Svaha";
	char	*copy;

	copy = ft_strdup(original);
	if (copy)
	{
		printf("Original: %s\n", original);
		printf("Copy: %s\n", copy);
		free(copy);
	}
	else
	{
		printf("Memory allocation failed.\n");
	}
	return (0);
}*/
