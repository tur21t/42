/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:39:47 by dmtur             #+#    #+#             */
/*   Updated: 2025/12/17 11:45:10 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_top_two(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
}

void	operation_sa(t_stack *a)
{
	swap_top_two(a);
	write(1, "sa\n", 3);
}

void	operation_sb(t_stack *b)
{
	swap_top_two(b);
	write(1, "sb\n", 3);
}

void	operation_ss(t_stack *a, t_stack *b)
{
	swap_top_two(a);
	swap_top_two(b);
	write(1, "ss\n", 3);
}
