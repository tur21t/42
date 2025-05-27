/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:29:34 by dmtur             #+#    #+#             */
/*   Updated: 2025/02/25 12:33:02 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	c;
	int	d;

	c = *a / *b;
	d = *a % *b;
	*a = c;
	*b = d;
}
/*#include <unistd.h>

int main(void)
{
    char    a;
    char    b;
    int x;
    int y;

    x = 9;
    y = 5;
    ft_ultimate_div_mod(&x, &y);
    a = x + '0';
    b = y + '0';
    write(1, "a: ", 3);
    write(1, &a, 1);
    write(1, "\n", 1);
    write(1, "b: ", 3);
    write(1, &b, 1);
    write(1, "\n", 1);
    return (0);
}*/
