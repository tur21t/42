/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 13:45:12 by dfrincu           #+#    #+#             */
/*   Updated: 2025/05/22 16:43:28 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return ((c >= 32 && c <= 126));
}
/*#include <stdio.h>
int main(void)
{
    char tests[] = {'a', 'Z', '1', '*', 'm', 'M', '\t', '\0'};
    int i = 0;

    while (tests[i])
    {
        if (ft_isprint(tests[i]))
            printf("'%c' es printable.\n", tests[i]);
        else
            printf("'%c' NO es printable.\n", tests[i]);
        i++;
    }
    return 0;
}*/
