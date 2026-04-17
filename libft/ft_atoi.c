/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:45:49 by dfrincu           #+#    #+#             */
/*   Updated: 2025/05/16 16:54:56 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
/*#include <stdio.h>
int main(void)
{
    printf("1. \"%s\" → %d\n", "42", ft_atoi("42"));
    printf("2. \"%s\" → %d\n", "   -123", ft_atoi("   -123"));
    printf("3. \"%s\" → %d\n", "+567", ft_atoi("+567"));
    printf("4. \"%s\" → %d\n", "  \t\n 98abc", ft_atoi("  \t\n 98abc"));
    printf("5. \"%s\" → %d\n", "abc42", ft_atoi("abc42"));
    printf("6. \"%s\" → %d\n", "", ft_atoi(""));
    printf("7. \"%s\" → %d\n", "0000123", ft_atoi("0000123"));

    return 0;
}*/
