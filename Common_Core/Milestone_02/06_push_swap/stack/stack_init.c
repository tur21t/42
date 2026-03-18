/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:42:17 by dmtur             #+#    #+#             */
/*   Updated: 2025/12/15 17:49:37 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Creates a new stack node with given value.
** Index is initialized to -1 (will be set later during indexing).
*/

t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

/*
** Initializes stack from an int array.
** The first array element becomes the top of the stack.
*/

void	stack_init_from_array(t_stack *stack, int *arr, int len)
{
	int		i;
	t_node	*new_node;

	stack->top = NULL;
	stack->size = 0;
	i = len - 1;
	while (i >= 0)
	{
		new_node = create_node(arr[i]);
		if (!new_node)
			return ;
		new_node->next = stack->top;
		stack->top = new_node;
		stack->size++;
		i--;
	}
}
