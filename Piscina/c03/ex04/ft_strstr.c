/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:46:47 by dmtur             #+#    #+#             */
/*   Updated: 2025/03/03 19:12:32 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	j;

	if (*to_find == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j] != '\0')
			j++;
		if (to_find[j] == '\0')
			return (&str[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int main()
{
    char str1[] = "Hello, world!";
    char str2[] = "world";
    char str3[] = "Hello";
    char str4[] = "";
    char str5[] = "xyz";

    printf("Test 1: %s\n", ft_strstr(str1, str2));
    printf("Test 2: %s\n", ft_strstr(str1, str3));
    printf("Test 3: %s\n", ft_strstr(str1, str4));
    printf("Test 4: %s\n", ft_strstr(str1, str5));
    return 0;
}*/
