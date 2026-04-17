/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:20:53 by dfrincu           #+#    #+#             */
/*   Updated: 2025/05/22 16:41:25 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*#include <stdio.h>
int main(void)
{
    char tests[] = {'a', 'Z', '1', '*', 'm', 'M', '2' ,'\0'};
    int i = 0;

    while (tests[i])
    {
        if (ft_isdigit(tests[i]))
            printf("'%c' es alfanumerico.\n", tests[i]);
        else
            printf("'%c' NO es alfanumerico.\n", tests[i]);
        i++;
    }
    return 0;
}*/
