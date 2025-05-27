/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <dmtur@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:58:32 by dmtur             #+#    #+#             */
/*   Updated: 2025/02/21 19:32:47 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n);

int ft_atoi(char *str)
{
    int i = 0;
    int num = 0;
    int sign = 1;

    // Handle negative numbers
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }

    // Convert each digit to an integer
    while (str[i] >= '0' && str[i] <= '9')
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }

    return num * sign;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "ERORR21", 7);
		return (1);
	}
	int num;
	num = ft_atoi(argv[1]); 
	ft_is_negative(num);
	return (0);
}
