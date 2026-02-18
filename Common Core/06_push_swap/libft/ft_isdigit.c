/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:37:12 by dmtur             #+#    #+#             */
/*   Updated: 2025/06/06 22:55:41 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int symb)
{
	if (symb >= '0' && symb <= '9')
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int main(void)
{
    int tests[] = {'0', '5', '9', 'a', ' ', '7', '/', ':', 48, 57};
    int size = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < size; i++)
    {
        int c = tests[i];
        int result = ft_isdigit(c);
        printf("ft_isdigit(%c) = %d\n", c, result);
    }
    return (0);
}*/
