/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:41:27 by dmtur             #+#    #+#             */
/*   Updated: 2025/03/05 14:46:18 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}
	return (length);
}
/*
#include <unistd.h>

void	print_number(int n)
{
	char	c;

	if (n >= 10)
		print_number(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	main(void)
{
	char	*green_tara = "Om Tare Tuttare Ture Svaha";
	char	*red_tara = "Om Tare Tam Svaha";

	print_number(ft_strlen(green_tara));
	write(1, "\n", 1);
	print_number(ft_strlen(red_tara));
	write(1, "\n", 1);
	return (0);
}*/
