/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:53:29 by dfrincu           #+#    #+#             */
/*   Updated: 2025/05/22 16:37:29 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
/*#include <stdio.h>
int main(void)
{
    char tests[] = {'a', 'Z', '1', '*', 'm', 'M', '\0'};
    int i = 0;

    while (tests[i])
    {
        if (ft_isalpha(tests[i]))
            printf("'%c' es una letra alfabética.\n", tests[i]);
        else
            printf("'%c' NO es una letra alfabética.\n", tests[i]);
        i++;
    }
    return 0;
}*/
