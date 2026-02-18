/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam02_tmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:30:36 by dmtur             #+#    #+#             */
/*   Updated: 2026/01/19 20:45:05 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4)|(octet << 4));
}


#include <unistd.h>
#include <stdio.h>

int main(void)
{
    unsigned char a = 0x41; // 0100 0001
    unsigned char b;

    b = swap_bits(a);

    printf("Before: 0x%02X\n", a);
    printf("After : 0x%02X\n", b);

    return (0);
}
