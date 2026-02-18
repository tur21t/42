/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam02_tmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:30:36 by dmtur             #+#    #+#             */
/*   Updated: 2026/01/29 17:12:38 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		int	start = 0;
		while (av[1][start] && (av[1][start] == ' ' || (av[1][start] >= '\t' && av[1][start] <= '\r')))
		{	
			start++;
	
		}
		int end = start;
		while (av[1][end] && av[1][end] != ' ' && !(av[1][end] >= '\t' && av[1][end] <= '\r'))
			end++;

		
		int	first_word_length = end - start;
		char	*first_word = malloc(first_word_length + 1);
		if (!first_word)
		{
			write(1, "\n", 1);
			return (0);
		}

		int	j = 0;
		while (j < first_word_length)
		{
			first_word[j] = av[1][start +j];
			j++;
		}
		first_word[j] = '\0';

		
		int	is_not_space = 1;
		int	first_word_printed = 0;
		int	i = end;
		while (av[1][i])		
		{
			if (av[1][i] == ' ' || (av[1][i] >= '\t' && av[1][i] <= '\r'))
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

		if (first_word_printed)
			write(1, " t", 2);
		
		j = 0;
		while (first_word[j])
		{
			write(1, &first_word[j], 1);
				j++;
		}
		free(first_word);
	}
	write(1, "\n", 1);
	return (0);
}
