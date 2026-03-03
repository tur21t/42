/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:30:36 by dmtur             #+#    #+#             */
/*   Updated: 2026/01/29 17:12:38 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include <unistd.h>

int     main(int ac, char **av)
{
        if(ac >= 2)
        {
                char    *s = av[1];
                int     i = 0;

                while (s[i] == ' ' || s[i] == '\t')
                        i++;
                while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t')
                        i++;
                while (s[i] == ' ' || s[i] == '\t')
                        i++;    
                while (s[i] != '\0')
                {       
                        while (s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
                        {
                                write(1, &s[i], 1);
                                i++;
                        }
                        while (s[i] == ' ' || s[i] == '\t')
                        {
                                i++;    
                        }
                        write(1, " ", 1);
                }
                i = 0;
                while (s[i] == ' ' || s[i] == '\t')
                        i++;
                while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t')
                {
                        write(1, &s[i], 1);
                        i++;
                }
        }
        write(1, "\n", 1);
        return (0);
}
/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/
