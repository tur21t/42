/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:18:23 by dmtur             #+#    #+#             */
/*   Updated: 2025/03/03 19:35:26 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_length;
	unsigned int	src_length;
	unsigned int	i;

	dest_length = 0;
	while (dest[dest_length] && dest_length < size)
		dest_length++;
	src_length = 0;
	while (src[src_length])
		src_length++;
	if (size <= dest_length)
		return (size + src_length);
	i = 0;
	while (src[i] && (dest_length + i) < (size - 1))
	{
		dest[dest_length + i] = src[i];
		i++;
	}
	dest[dest_length + i] = '\0';
	return (dest_length + src_length);
}
/*
#include <stdio.h>

int main()
{
	char str1[20] = "Hello, ";
	char str2[] = "world!";
    
	unsigned int result = ft_strlcat(str1, str2, sizeof(str1));
	
	printf("After: %s\n", str1);
	printf("Total Length: %u\n", result);
	return 0;
}*/
