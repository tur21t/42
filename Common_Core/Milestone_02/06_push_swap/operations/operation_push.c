/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:49:47 by dmtur             #+#    #+#             */
/*   Updated: 2025/12/17 11:51:48 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operation_pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!b || b->size == 0)
	{
		write(1, "pa\n", 3);
		return ;
	}
	node = pop_node(b);
	push_node(a, node);
	write(1, "pa\n", 3);
}

void	operation_pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!a || a->size == 0)
	{
		write(1, "pb\n", 3);
		return ;
	}
	node = pop_node(a);
	push_node(b, node);
	write(1, "pb\n", 3);
}
