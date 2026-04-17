/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 10:46:11 by dmtur             #+#    #+#             */
/*   Updated: 2026/01/06 20:45:38 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_node(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	node->next = stack->top;
	stack->top = node;
	stack->size++;
}

t_node	*pop_node(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->top)
		return (NULL);
	node = stack->top;
	stack->top = node->next;
	node->next = NULL;
	stack->size--;
	return (node);
}

t_node	*stack_last_node(t_stack *stack)
{
	t_node	*cur;

	if (!stack || !stack->top)
		return (NULL);
	cur = stack->top;
	while (cur->next)
		cur = cur->next;
	return (cur);
}

int	peek_value(t_stack *stack)
{
	if (!stack || !stack->top)
		return (0);
	return (stack->top->value);
}
