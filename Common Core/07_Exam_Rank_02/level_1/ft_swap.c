/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 12:56:39 by dmtur             #+#    #+#             */
/*   Updated: 2025/10/22 13:32:40 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

#include <stdio.h>
#include <stdlib.h>

int	 main(int argc, char **argv)
{
        int	a;
        int	b;

        if (argc != 3)
        {
                printf("Usage: %s <a> <b>\n", argv[0]);
                return (1);
        }

        a = atoi(argv[1]);  // convert first argument to int
        b = atoi(argv[2]);  // convert second argument to int

        printf("a before: %d\n", a);
        printf("b before: %d\n", b);

        ft_swap(&a, &b);

        printf("a after: %d\n", a);
        printf("b after: %d\n", b);
	return (0);
}
