/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:08:41 by dmtur             #+#    #+#             */
/*   Updated: 2025/02/25 13:30:31 by dmtur            ###   ########.fr       */
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

void ft_putnbr(int n)
{
    char c;

    if (n > 9)
        ft_putnbr(n / 10);

    c = (n % 10) + '0';
    write(1, &c, 1);
}

int main(void)
{
    int length = ft_strlen("Hello, world_RD13!");
    
    write(1, "Length: ", 8);
    ft_putnbr(length);
    write(1, "\n", 1);
    
    return (0);
}*/
