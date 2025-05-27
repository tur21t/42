/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:32:16 by dmtur             #+#    #+#             */
/*   Updated: 2025/02/25 14:14:09 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	left;
	int	right;

	left = 0;
	right = size - 1;
	while (left < right)
	{
		temp = tab[left];
		tab[left] = tab[right];
		tab[right] = temp;
		left++;
		right--;
	}
}
/*
#include <unistd.h>

int main(void)
{
    int tab[] = {1, 2, 3, 4, 5};
    int size = 5;
    int i;
    char c;

    ft_rev_int_tab(tab, size);

    i = 0;
    while (i < size)
    {
        c = tab[i] + '0';
        write(1, &c, 1);
        write(1, " ", 1);
        i++;
    }
    write(1, "\n", 1);
    return (0);
}*/
