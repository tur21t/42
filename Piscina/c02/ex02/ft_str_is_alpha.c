/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:55:03 by dmtur             #+#    #+#             */
/*   Updated: 2025/03/01 20:01:13 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!(
				(str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= 'a' && str[i] <= 'z')
			))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
/*
#include <unistd.h>

int	main(void)
{
	char	*test;
	
	test = "";
//	test = "OmTareTuttareTureSvaha";
	if (ft_str_is_alpha(test))
		write(1, "Only letters or empty\n", 23);
	else
		write(1, "Contains non-letters\n", 21);
	return (0);
}*/
