/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:19:19 by dmtur             #+#    #+#             */
/*   Updated: 2025/02/26 14:25:59 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	temp = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (tab[j] > tab[j +1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}
/*#include <unistd.h>

int main(void)
{
    int tab[] = {5, 3, 7, 1, 9};
    int size = 5;
    int i;
    char c;

    ft_sort_int_tab(tab, size);

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
