/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 20:08:39 by dmtur             #+#    #+#             */
/*   Updated: 2025/03/01 20:40:31 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
/*
#include <unistd.h>

int	main(void)
{
	if (ft_str_is_numeric("test21t"))
		write(1, "test1: Only digits or empty\n", 28);
	else
		write(1, "test1: non-digits\n", 18);
	if (ft_str_is_numeric(""))
		write(1, "test2: Only digits or empty\n", 28);
	else
		write(1, "test2: non-digits\n", 18);
	if (ft_str_is_numeric("21"))
		write(1, "test3: Only digits or empty\n", 28);
	else
		write(1, "test3: non-digits\n", 18);
	return (0);
}*/
