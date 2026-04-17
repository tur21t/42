/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:30:36 by dmtur             #+#    #+#             */
/*   Updated: 2026/02/19 14:11:48 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	is_not_space = 1;
		int	first_word_printed = 0;
		int	i = 0;
		while (av[1][i])		
		{
			if (av[1][i] == ' ' || av[1][i] == '\t')
			{
				is_not_space = 0;			
			} else 
			{
				if (is_not_space == 0 && first_word_printed == 1)
					write(1, " ", 1);
				is_not_space = 1;
				first_word_printed = 1;
				write(1, &av[1][i], 1);
			}

			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

/*
 Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n.

Example:

$> ./epur_str "vous voyez c'est facile d'afficher la meme chose" | cat -e
vous voyez c'est facile d'afficher la meme chose$
$> ./epur_str " seulement          la c'est      plus dur " | cat -e
seulement la c'est plus dur$
$> ./epur_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./epur_str "" | cat -e
$
$>*/
