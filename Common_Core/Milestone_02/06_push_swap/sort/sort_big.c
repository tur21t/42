/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 19:43:11 by dmtur             #+#    #+#             */
/*   Updated: 2025/12/20 19:55:22 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_by_bit(t_stack *a, t_stack *b, int bit)
{
	int	processed;
	int	size;

	size = a->size;
	processed = 0;
	while (processed < size)
	{
		if (((a->top->index >> bit) & 1) == 0)
			operation_pb(a, b);
		else
			operation_ra(a);
		processed++;
	}
}

void	sort_big(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	i;
	int	size;

	if (!a || a->size < 2)
		return ;
	size = a->size;
	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		push_by_bit(a, b, i);
		while (b->size > 0)
			operation_pa(a, b);
		i++;
	}
}
