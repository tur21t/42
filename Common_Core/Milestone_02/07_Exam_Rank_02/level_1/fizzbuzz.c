/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam02_tmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:30:36 by dmtur             #+#    #+#             */
/*   Updated: 2026/01/17 20:43:29 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_num(int n)
{
	char c;

	if (n > 9)
		write_num(n/10);
	c = (n % 10) + '0';
	write(1, &c, 1);

}

int	main(void)
{
	int i;

	i = 1;
	while(i <= 100)
	{
		if (i % 15 == 0)
		       write(1, "fizzbuzz", 8);
		else if (i % 5 == 0)
		       write(1, "buzz", 4);
		else if (i % 3 == 0)
		       write(1, "fizz", 4);
		else write_num(i);
		write(1, "\n", 1);
		i++;
	}

	return(0);
}
