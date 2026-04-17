/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:02:12 by dfrincu           #+#    #+#             */
/*   Updated: 2025/05/22 16:49:26 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return ((c >= 0 && c <= 127));
}
/*#include <stdio.h>
int main(void)
{
    int tests[] = {'a', 'Z', 127, 128, 200, -5, 0};
    int i = 0;

    while (i < (int)(sizeof(tests) / sizeof(tests[0])))
    {
        if (ft_isascii(tests[i]))
            printf("'%d' es ASCII.\n", tests[i]);
        else
            printf("'%d' NO es ASCII.\n", tests[i]);
        i++;
    }
    return 0;
}*/
