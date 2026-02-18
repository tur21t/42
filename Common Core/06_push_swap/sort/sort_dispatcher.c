/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dispatcher.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 20:01:12 by dmtur             #+#    #+#             */
/*   Updated: 2025/12/20 20:05:18 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_dispatcher(t_stack *a, t_stack *b)
{
	if (!a || a->size < 2)
		return ;
	if (is_sorted_ascending(a))
		return ;
	if (a->size <= 5)
		sort_small(a, b);
	else
		sort_big(a, b);
}
