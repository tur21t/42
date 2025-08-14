/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:38:42 by dmtur             #+#    #+#             */
/*   Updated: 2025/06/06 23:19:20 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int symb)
{
	if (symb >= 'a' && symb <= 'z')
		return (symb - 32);
	else
		return (symb);
}
/*
#include <stdio.h>

int	main(void)
{
    int tests[] = {'t', 'u', 'r', '2', '1', 'A', '@', '`'};
    int size = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < size; i++)
    {
        int c = tests[i];
        int result = ft_toupper(c);
        printf("ft_toupper('%c') = '%c' (ASCII %d)\n", c, result, result);
    }
    return (0);
}*/
