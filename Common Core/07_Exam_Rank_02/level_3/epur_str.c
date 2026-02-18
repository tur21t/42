/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam02_tmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:30:36 by dmtur             #+#    #+#             */
/*   Updated: 2026/01/28 16:23:14 by dmtur            ###   ########.fr       */
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
