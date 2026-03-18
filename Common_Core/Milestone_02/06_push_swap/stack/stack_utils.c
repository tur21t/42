/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:16:19 by dmtur             #+#    #+#             */
/*   Updated: 2026/01/07 16:19:03 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_min_value(t_stack *stack)
{
	t_node	*cur;
	int		min;

	if (!stack || stack->size == 0)
		return (0);
	cur = stack->top;
	min = cur->value;
	while (cur)
	{
		if (cur->value < min)
			min = cur->value;
		cur = cur->next;
	}
	return (min);
}

int	stack_find_position(t_stack *stack, int value)
{
	t_node	*cur;
	int		pos;

	cur = stack->top;
	pos = 0;
	while (cur)
	{
		if (cur->value == value)
			return (pos);
		cur = cur->next;
		pos++;
	}
	return (-1);
}
