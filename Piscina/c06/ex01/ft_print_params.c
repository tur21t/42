/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:37:24 by dmtur             #+#    #+#             */
/*   Updated: 2025/03/06 14:37:30 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		i;
	int		arg_index;
	char	*current_arg;

	arg_index = 1;
	while (arg_index < argc)
	{
		current_arg = argv[arg_index];
		i = 0;
		while (current_arg[i] != '\0')
		{
			write(1, &current_arg[i], 1);
			i++;
		}
		write(1, "\n", 1);
		arg_index++;
	}
	return (0);
}
