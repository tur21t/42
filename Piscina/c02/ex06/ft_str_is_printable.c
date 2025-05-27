/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:46:10 by dmtur             #+#    #+#             */
/*   Updated: 2025/03/02 17:07:16 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			return (0);
		i++;
	}
	return (1);
}
/*
#include <unistd.h>

int	main(void)
{
	if (ft_str_is_printable(""))
		write(1, "t1: Only printable or empty\n", 29);
	else
		write(1, "t1: Contains non-printable\n", 28);
	if (ft_str_is_printable("Hello, World!"))
		write(1, "t2: Only printable or empty\n", 29);
	else
		write(1, "t2: Contains non-printable\n", 28);
	if (ft_str_is_printable("Hello\nWorld"))
		write(1, "t3: Only printable or empty\n", 29);
	else
		write(1, "t3: Contains non-printable\n", 28);
	return (0);
}*/
