/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:00:01 by dmtur             #+#    #+#             */
/*   Updated: 2025/03/02 15:43:48 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
			return (0);
		i++;
	}
	return (1);
}
/*
#include <unistd.h>

int	main(void)
{
	if (ft_str_is_lowercase(""))
		write(1, "t1: Only lowercase or empty\n", 28);
	else
		write(1, "t1: Contains something else\n", 28);
	if (ft_str_is_lowercase("OmTareTuttareTureSvaha"))
		write(1, "t2: Only lowercase or empty\n", 28);
	else
		write(1, "t2: Contains something else\n", 28);
	if (ft_str_is_lowercase("tashideleg"))
		write(1, "t3: Only lowercase or empty\n", 28);
	else
		write(1, "t3: Contains something else\n", 28);
	return (0);
}*/
