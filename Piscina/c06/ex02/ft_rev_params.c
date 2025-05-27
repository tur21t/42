/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:45:12 by dmtur             #+#    #+#             */
/*   Updated: 2025/03/06 14:50:56 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		i;
	int		arg_index;
	char	*current_arg;

	arg_index = argc - 1;
	while (arg_index > 0)
	{
		current_arg = argv[arg_index];
		i = 0;
		while (current_arg[i] != '\0')
		{
			write(1, &current_arg[i], 1);
			i++;
		}
		write(1, "\n", 1);
		arg_index--;
	}
	return (0);
}
