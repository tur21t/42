/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 18:34:27 by dmtur             #+#    #+#             */
/*   Updated: 2025/03/02 21:39:50 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
/*
#include <unistd.h>

void print_number(int n)
{
    char c;

    if (n < 0)
    {
        write(1, "-", 1);
        n = -n;
    }
    if (n >= 10)
        print_number(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
}

int main(void)
{
	char	*s1 = "Om Tare Tuttare Ture Soha";
	char	*s2 = "Tashi Delek";
	char	*s3 = "Om Tare Tuttare Ture Soha";

	write(1, "Test 1: ", 8);
	print_number(ft_strcmp(s1, s3));
	write(1, "\n", 1);

	write(1, "Test 2: ", 8);
	print_number(ft_strcmp(s1, s2));
	write(1, "\n", 1);

	return (0);
}*/
