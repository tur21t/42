/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:40:43 by dmtur             #+#    #+#             */
/*   Updated: 2025/06/06 23:13:20 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int symb)
{
	if (symb >= 'A' && symb <= 'Z')
		return (symb + 32);
	else
		return (symb);
}
/*
#include <stdio.h>

int	main(void)
{
    int tests[] = {'A', 't', 'u', 'R', '2', '1', '@', '['};
    int size = sizeof(tests) / sizeof(tests[0]);

    for (int i = 0; i < size; i++)
    {
        int c = tests[i];
        int result = ft_tolower(c);
        printf("ft_tolower('%c') = '%c' (ASCII %d)\n", c, result, result);
    }
    return (0);
}*/
