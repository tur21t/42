/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:22:00 by dmtur             #+#    #+#             */
/*   Updated: 2025/03/03 17:29:14 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	dest_length;

	i = 0;
	dest_length = 0;
	while (dest[dest_length] != '\0')
	{
		dest_length++;
	}
	while (src[i] != '\0')
	{
		dest[dest_length + i] = src[i];
		i++;
	}
	dest[dest_length + i] = '\0';
	return (dest);
}
/*
#include <stdio.h>

int main()
{
    char str1[50] = "Hello, ";
    char str2[] = "friend!";

    printf("Before: %s\n", str1);
    ft_strcat(str1, str2);
    printf("After: %s\n", str1);

    return 0;
}*/
