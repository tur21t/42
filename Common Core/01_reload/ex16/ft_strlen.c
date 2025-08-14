/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:25:05 by dmtur             #+#    #+#             */
/*   Updated: 2025/05/06 17:51:50 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
/*
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putnbr(int nb)
{
    if (nb >= 10)
        ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + '0');
}

int     main(void)
{
    int len;

    len = ft_strlen("OmTareTuttareTureSvaha");
    ft_putnbr(len);
    ft_putchar('\n');
    return (0);
}*/
