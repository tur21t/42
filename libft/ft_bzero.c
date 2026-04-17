/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:30:56 by dfrincu           #+#    #+#             */
/*   Updated: 2025/05/16 14:30:17 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}
/*#include <stdio.h>
int main(void)
{
    char str[20] = "Hola mundo!";

    printf("Antes ft_bzero: %s\n", str);

    ft_bzero(str + 5, 6); 

    printf("Después ft_bzero: %s\n", str);

    return 0;
}*/
