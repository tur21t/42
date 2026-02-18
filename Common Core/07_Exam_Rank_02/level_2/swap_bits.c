/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 02:11:22 by dmtur             #+#    #+#             */
/*   Updated: 2025/11/17 02:13:58 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

void    print_bits(unsigned char octet)
{
    int     i = 7;
    char    bit;

    while (i >= 0)
    {
        bit = ((octet >> i) & 1) + '0';
        write(1, &bit, 1);
        i--;
    }
}

int main(void)
{
    unsigned char x = 182; // 1011 0110

    write(1, "Original: ", 10);
    print_bits(x);
    write(1, "\n", 1);

    unsigned char swapped = swap_bits(x);

    write(1, "Swapped : ", 10);
    print_bits(swapped);
    write(1, "\n", 1);

    return 0;
}
