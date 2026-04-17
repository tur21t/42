/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:32:32 by dmtur             #+#    #+#             */
/*   Updated: 2025/03/02 17:37:48 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

#include <unistd.h>

void    ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

int main(void)
{
    char mantra[] = "OmTareTuttareTureSvaha";
    char greeting[] = "TashiDelek";

    ft_putstr("Before: "); ft_putstr(mantra); write(1, "\n", 1);
    ft_strlowcase(mantra);
    ft_putstr("After: "); ft_putstr(mantra); write(1, "\n\n", 2);

    ft_putstr("Before: "); ft_putstr(greeting); write(1, "\n", 1);
    ft_strlowcase(greeting);
    ft_putstr("After: "); ft_putstr(greeting); write(1, "\n", 1);

    return (0);
}
