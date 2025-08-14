/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:32:44 by dmtur             #+#    #+#             */
/*   Updated: 2025/06/06 22:41:03 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int symb)
{
	if ((symb >= 'A' && symb <= 'Z' ) || (symb >= 'a' && symb <= 'z'))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int main(void)
{
    char tests[] = {'N', 'a', 'm', 'o', '*', 'T', 'a', 'r', 'a', '\n', '7', '*'};
    int size = sizeof(tests) / sizeof(tests[0]);
    for (int i = 0; i < size; i++)
    {
        char c = tests[i];
        int result = ft_isalpha(c);
        printf("ft_isalpha('%c') = %d\n", 
	(c >= 32 && c <= 126 ? c : '?'), 
	result);
    }
    return (0);
}*/
