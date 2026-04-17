/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:47:59 by dmtur             #+#    #+#             */
/*   Updated: 2025/06/06 23:06:33 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int symb)
{
	if (symb >= 32 && symb <= 126)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int main(void)
{
    int tests[] = {31, 32, 't', 90, 97, 126, 127, 200, ' '};
    int size = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < size; i++)
    {
        int c = tests[i];
        int result = ft_isprint(c);
        printf("ft_isprint(%d) = %d\n", c, result);
    }
    return (0);
}*/
