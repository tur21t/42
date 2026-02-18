/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:23:48 by dmtur             #+#    #+#             */
/*   Updated: 2025/12/15 10:32:15 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Entry point of push_swap
** Flow:
** 1) Parse and validate input arguments
** 2) Initialize stacks a and b
** 3) If stack a is not sorted, choose and run sorting algorithm
** 4) Free allocated memory and exit
*/

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*values;
	int		values_count;

	if (argc < 2)
		return (0);
	values = parse_arguments(argc, argv, &values_count);
	if (!values)
		print_error_and_exit();
	stack_a.top = NULL;
	stack_a.size = 0;
	stack_b.top = NULL;
	stack_b.size = 0;
	stack_init_from_array(&stack_a, values, values_count);
	free(values);
	if (!is_sorted_ascending(&stack_a))
	{
		assign_indexes(&stack_a);
		sort_dispatcher(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
