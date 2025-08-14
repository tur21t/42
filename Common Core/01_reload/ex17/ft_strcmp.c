/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 18:52:49 by dmtur             #+#    #+#             */
/*   Updated: 2025/05/07 19:17:35 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
#include <unistd.h>

void    print_result(int result)
{
    if (result == 0)
        write(1, "Equal\n", 6);
    else if (result < 0)
        write(1, "First < Second\n", 15);
    else
        write(1, "First > Second\n", 15);
}

int     main(void)
{
    int result;

    // Test 1: Tara mantra and Tara mantra
    result = ft_strcmp("Namo Tara", "Namo Tara");
    write(1, "Tara and Tara: ", 15);
    print_result(result);

    // Test 2: Tara and Vajra Sarasvati
    result = ft_strcmp("Om Tare Tuttare Ture Svaha", "Namo Vajra Sarasvati");
    write(1, "Tara and Vajra Sarasvati: ", 27);
    print_result(result);

    // Test 3: Tara and Manjushri
    result = ft_strcmp("Om Tare Tuttare Ture Svaha", "Om Ah Ra Pa Tsa Na Dhih");
    write(1, "Tara and Manjushri: ", 21);
    print_result(result);

    return (0);
}*/
