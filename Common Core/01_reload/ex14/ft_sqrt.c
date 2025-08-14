/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 21:22:17 by dmtur             #+#    #+#             */
/*   Updated: 2025/05/05 21:47:49 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i <= nb / i)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int main(void)
{
    int test_values[] = {0, 1, 4, 9, 16, 25, 26, 2147395600, 2147483647};
    int i;

    for (i = 0; i < 9; i++)
    {
        int nb = test_values[i];
        int result = ft_sqrt(nb);
        printf("ft_sqrt(%d) = %d\n", nb, result);
    }

    return 0;
}*/
