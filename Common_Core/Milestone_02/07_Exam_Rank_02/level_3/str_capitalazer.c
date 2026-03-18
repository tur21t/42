/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalazer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:48:27 by dmtur             #+#    #+#             */
/*   Updated: 2026/02/19 14:48:51 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
    int i = 1;
    int j;
    char c;

    if (ac == 1)
    {
        write(1, "\n", 1);
        return 0;
    }

    while (i < ac)
    {
        j = 0;
        while (av[i][j])
        {
            c = av[i][j];

            // Make everything lowercase first
            if (c >= 'A' && c <= 'Z')
                c += 32;

            // Capitalize if first char or previous char is space/tab/newline
            if ((c >= 'a' && c <= 'z') && (j == 0 || av[i][j - 1] <= 32))
                c -= 32;

            write(1, &c, 1);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }

    return 0;
}

