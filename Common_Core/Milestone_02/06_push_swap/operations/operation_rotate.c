/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:14:01 by dmtur             #+#    #+#             */
/*   Updated: 2025/12/17 12:16:17 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack_up(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	stack->top = first->next;
	first->next = NULL;
	last = stack_last_node(stack);
	last->next = first;
}

void	operation_ra(t_stack *a)
{
	rotate_stack_up(a);
	write(1, "ra\n", 3);
}

void	operation_rb(t_stack *b)
{
	rotate_stack_up(b);
	write(1, "rb\n", 3);
}

void	operation_rr(t_stack *a, t_stack *b)
{
	rotate_stack_up(a);
	rotate_stack_up(b);
	write(1, "rr\n", 3);
}
