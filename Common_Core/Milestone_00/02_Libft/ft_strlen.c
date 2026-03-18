/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 20:51:17 by dmtur             #+#    #+#             */
/*   Updated: 2025/06/07 19:53:33 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
    const char *tests[] = {
        "",
        "a",
        "a lama chenno",
        "Om Tare Tuttare Ture Svaha",
        "21",
        "👋🌍",
        NULL
    };

    for (int i = 0; tests[i] != NULL; i++)
    {
        size_t my_len = ft_strlen(tests[i]);
        size_t real_len = strlen(tests[i]);
        printf("Test %d: \"%s\"\n", i, tests[i]);
        printf("ft_strlen: %zu | strlen: %zu\n\n", my_len, real_len);
    }

    return (0);
}*/
