/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 20:23:39 by dmtur             #+#    #+#             */
/*   Updated: 2026/02/10 21:02:55 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	i = 0;

	while(begin_list)
	{
		begin_list = begin_list->next;
		i++;	
	}
	return (i);
}

void	ft_list_foreach()
