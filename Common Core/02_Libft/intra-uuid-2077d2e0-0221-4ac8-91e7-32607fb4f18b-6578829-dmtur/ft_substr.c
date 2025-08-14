/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 00:25:58 by dmtur             #+#    #+#             */
/*   Updated: 2025/06/17 00:47:30 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_empty_string(void)
{
	char	*sub;

	sub = (char *)malloc(1);
	if (!sub)
		return (NULL);
	sub[0] = '\0';
	return (sub);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_empty_string());
	if (len > s_len - start)
		len = s_len - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*sub;

        sub = ft_substr("Om Tare Tuttare Ture", 3, 4);
        if (sub)
        {
                printf("Substr: %s\n", sub);
                free(sub);
        }

        sub = ft_substr("Granja Taronja", 50, 4);
        if (sub)
        {
                printf("Out of bounds: %s\n", sub);
                free(sub);
        }

        return (0);
}*/
