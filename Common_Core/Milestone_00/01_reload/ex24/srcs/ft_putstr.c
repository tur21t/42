/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:51:33 by dmtur             #+#    #+#             */
/*   Updated: 2025/05/06 16:27:13 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}
/*
#include <unistd.h>

int	main(void)
{
	ft_putstr("test_ft_putstr_21t");
	write(1, "\n", 1);
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}*/
