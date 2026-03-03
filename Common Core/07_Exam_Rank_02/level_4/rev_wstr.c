/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 20:55:31 by dmtur             #+#    #+#             */
/*   Updated: 2026/02/24 23:19:10 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

#include <unistd.h>

int     main(int ac, char **av)
{
        if (ac == 2)
        {
				int     start = 0;
				int     i = 0;
				int     end = 0;
                char    *s = av[1];
                
                while (s[end] != '\0')
                        end++;
                while (end > 0)
                {
                        start = end  - 1;
                        while (start >= 0 && s[start] != ' ' && s[start] != '\t')
                                start--;
                        i = start + 1;
                        while (i < end)
                        {
                                write(1, &s[i], 1);
                                i++;
                        }
                        if (start > 0)
                        {
                                write(1, " ", 1);
                        }
                        end = start;
                }
        }
        write(1, "\n", 1);
        return (0);
}


/*Expected files : rev_wstr.c
Allowed functions: write, malloc, free
-------------------------------------------------------------------------------
Write a program that takes a string as a parameter, and prints its words in reverse order. A "word" is a part of
the string bounded by spaces and/or tabs, or the begin/end of the string. If the number of parameters is
different from 1, the program will display '\n'. In the parameters that are going to be tested, there won't be any
"additional" spaces (meaning that there won't be additionnal spaces at the beginning or at the end of the string,
and words will always be separated by exactly one space). Examples:
$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
-------------------------------------------------------------------------------
include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        char *s = av[1];
        int end = 0;
        int i = 0;

        while (s[i])
            i++;
        end = i;

        while (end > 0)
        {
            int start = end - 1;

            while (start >= 0 && s[start] != ' ' && s[start] != '\t')
                start--;

            int i = start + 1;
            while (i < end)
            {
                write(1, &s[i], 1);
                i++;
            }

            if (start > 0)
                write(1, " ", 1);

            end = start;
        }
    }
    write(1, "\n", 1);
    return (0);
}
*/
