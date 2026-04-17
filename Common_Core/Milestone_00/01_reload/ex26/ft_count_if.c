/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:42:12 by dmtur             #+#    #+#             */
/*   Updated: 2025/05/14 18:15:24 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (tab[i] != 0)
	{
		if (f(tab[i]) == 1)
			count++;
		i++;
	}
	return (count);
}
/*
#include <unistd.h>

int	ft_count_if(char **tab, int (*f)(char*));

int	is_red(char *str)
{
	int	i = 0;
	char *red = "red";

	while (str[i] && red[i] && str[i] == red[i])
		i++;
	return (red[i] == '\0' && str[i] == '\0');
}

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	main(void)
{
	char *array1[] = {"yes", "no", "red", "maybe", "yes", 0};
	char *array2[] = {"red", "RED", "red", "Red", "red", 0};
	int result1 = ft_count_if(array1, &is_red);
	int result2 = ft_count_if(array2, &is_red);

	write(1, "array1 -- 'red': ", 16);
	ft_putnbr(result1);
	write(1, "\n", 1);
        write(1, "array2 -- 'red': ", 16);
        ft_putnbr(result2);
        write(1, "\n", 1);


	return (0);
}*/
