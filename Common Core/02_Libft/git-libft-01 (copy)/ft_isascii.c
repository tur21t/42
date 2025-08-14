/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:46:11 by dmtur             #+#    #+#             */
/*   Updated: 2025/06/06 22:51:08 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int symb)
{
	if (symb >= 0 && symb <= 127)
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int main(void)
{
    int tests[] = {-1, 0, 21, 69, 't', '2', '1', 127, 128, 221};
    int size = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < size; i++)
    {
        int c = tests[i];
        int result = ft_isascii(c);
        printf("ft_isascii(%d) = %d\n", c, result);
    }
    return (0);
}*/
