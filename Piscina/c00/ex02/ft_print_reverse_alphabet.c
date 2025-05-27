/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:52:26 by dmtur             #+#    #+#             */
/*   Updated: 2025/02/14 14:10:46 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_reverse_alphabet(void)

{
    char letter = 'z';

    while (letter >= 'a')
    {
        write(1, &letter, 1);
        letter--;
    }
}
