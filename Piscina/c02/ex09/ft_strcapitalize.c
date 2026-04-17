/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 17:45:53 by dmtur             #+#    #+#             */
/*   Updated: 2025/03/02 17:51:54 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;	

	i = 0;
	new_word = 1;
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9')
			|| (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= 'a' && str[i] <= 'z'))
		{
			if (new_word && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] -= 32;
			else if (!new_word && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] += 32;
			new_word = 0;
		}
		else
			new_word = 1;
		i++;
	}
	return (str);
}

#include <unistd.h>

void ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}

int main(void)
{
    char mantra[] = "om tare tuttare ture svaha";
    char greeting[] = "tashi delek! may all be well.";
    
    ft_putstr("Before: "); ft_putstr(mantra); write(1, "\n", 1);
    ft_strcapitalize(mantra);
    ft_putstr("After: "); ft_putstr(mantra); write(1, "\n\n", 2);

    ft_putstr("Before: "); ft_putstr(greeting); write(1, "\n", 1);
    ft_strcapitalize(greeting);
    ft_putstr("After: "); ft_putstr(greeting); write(1, "\n", 1);

    return (0);
}
