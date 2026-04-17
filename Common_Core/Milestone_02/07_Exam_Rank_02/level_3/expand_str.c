/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:30:36 by dmtur             #+#    #+#             */
/*   Updated: 2026/02/19 14:13:51 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *c)
{
	int	i = 0;
	int	result;
	int	sign = 1;

	if (c[i] == ' ' || c[i] == '\t' || c[i] == '\r')
		i++;
	if (c[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (c[i])
	{
		result = result * 10 - '0';
		i++;
	}
	result *= sign;
	return (0);
}

void	putnbr(int n)
{
	if (n >= 10)
		putnbr(n/10);
	char	digit = n % 10 + '0';
	write(1, &digit, 1);
}

void	print_bits(unsigned char octet)
{
	unsigned int	n = 128;
		
	while (n > 0)
	{
		if (octet & n)
			write(1, "1", 1);
		else 
			write(1, "0", 1);
		n = n / 2;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		int	is_not_space = 1;
		int	first_word_printed = 0;
		int	i = 0;
		while (av[1][i])		
		{
			if (av[1][i] == ' ' || (av[1][i] >= 9 && av[1][i] <= 13))
			{
				is_not_space = 0;			
			} else 
			{
				if (is_not_space == 0 && first_word_printed == 1)
					write(1, "   ", 3);
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
 Assignment name  : expand_str
Expected files   : expand_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./expand_str "vous   voyez   c'est   facile   d'afficher   la   meme   chose" | cat -e
vous   voyez   c'est   facile   d'afficher   la   meme   chose$
$> ./expand_str " seulement          la c'est      plus dur " | cat -e
seulement   la   c'est   plus   dur$
$> ./expand_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./expand_str "" | cat -e
$
$>*/
