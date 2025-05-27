/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:13:50 by dmtur             #+#    #+#             */
/*   Updated: 2025/02/25 11:15:52 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
#include <unistd.h>

int main(void){

	int div;
	int mod;

    ft_div_mod(21, 9, &div, &mod);

    char div_char = div + '0';
    char mod_char = mod + '0';

    write(1, "div: ", 5);
    write(1, &div_char, 1);
    write(1, "\n", 1);
    write(1, "mod: ", 5);
	write(1, &mod_char, 1);
	write(1, "\n", 1);
	return (0);
}*/
