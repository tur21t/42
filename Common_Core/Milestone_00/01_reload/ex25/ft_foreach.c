/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:29:03 by dmtur             #+#    #+#             */
/*   Updated: 2025/05/13 15:56:54 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}
/*
#include <unistd.h>

void	ft_putdigit(int n)
{
	char	c;

	if (n >= 0 && n <= 9)
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

void	print_even_or_odd(int n)
{
	if (n % 2 == 0)
		write(1, "even\n", 5);
	else
		write(1, "odd\n", 4);
}

int	main(void)
{
	int	numbers1[] = {8, 4, 0, 0, 0};
	int	numbers2[] = {1, 0, 8, 21};

	write(1, "Test 1 (digits): ", 17);
	ft_foreach(numbers1, 5, &ft_putdigit);
	write(1, "\n", 1);

	write(1, "Test 2 (even/odd):\n", 19);
	ft_foreach(numbers2, 4, &print_even_or_odd);

	return (0);
}*/
