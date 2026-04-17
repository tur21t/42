/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 15:45:42 by dmtur             #+#    #+#             */
/*   Updated: 2025/03/02 16:39:52 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
			return (0);
		i++;
	}
	return (1);
}

#include <unistd.h>

int main(void)
{
    if (ft_str_is_uppercase(""))
        write(1, "t1: Only uppercase or empty\n", 28);
    else
        write(1, "t1: Contains something else\n", 28);
    if (ft_str_is_uppercase("OmTareTuttareTureSvaha"))
        write(1, "t2: Only uppercase or empty\n", 28);
    else
        write(1, "t2: Contains something else\n", 28);
    if (ft_str_is_uppercase("TASHIDELEG"))
        write(1, "t3: Only uppercase or empty\n", 28);
    else
        write(1, "t3: Contains something else\n", 28);
    return (0);
}
