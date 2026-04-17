/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:59:26 by dmtur             #+#    #+#             */
/*   Updated: 2025/12/17 16:23:17 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		operation_sa(a);
}

static void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second < third && first < third)
		operation_sa(a);
	else if (first > second && second > third)
	{
		operation_sa(a);
		operation_rra(a);
	}
	else if (first > second && second < third && first > third)
		operation_ra(a);
	else if (first < second && second > third && first < third)
	{
		operation_sa(a);
		operation_ra(a);
	}
	else if (first < second && second > third && first > third)
		operation_rra(a);
}

static void	sort_five(t_stack *a, t_stack *b)
{
	int	min;

	while (a->size > 3)
	{
		min = stack_min_value(a);
		while (a->top->value != min)
		{
			if (stack_find_position(a, min) <= a->size / 2)
				operation_ra(a);
			else
				operation_rra(a);
		}
		operation_pb(a, b);
	}
	sort_three(a);
	while (b->size > 0)
		operation_pa(a, b);
}

void	sort_small(t_stack *a, t_stack *b)
{
	if (is_sorted_ascending(a))
		return ;
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_five(a, b);
}
