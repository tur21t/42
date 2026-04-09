/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:35:53 by dfrincu           #+#    #+#             */
/*   Updated: 2026/03/23 14:35:54 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_pipeline(t_cmd *cmds)
{
	t_cmd	*curr;
	int		count;

	curr = cmds;
	count = 0;
	while (curr)
	{
		if (curr->infile == 0)
			curr->infile = STDIN_FILENO;
		if (curr->outfile == 0)
			curr->outfile = STDOUT_FILENO;
		count++;
		curr = curr->next;
	}
	return (count);
}
