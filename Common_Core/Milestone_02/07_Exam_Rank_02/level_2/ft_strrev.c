/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 22:11:55 by dmtur             #+#    #+#             */
/*   Updated: 2025/11/30 22:41:46 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int	i;
	int	length;
	char	tmp;
	
	i = 0;
	length = 0;
	while(str[length])
		length++;
	length--;
	while(length > i)
	{
		tmp = str[i];
		str[i] = str[length];
		str[length] = tmp;
		length--;
		i++;
	}
	return (str);

}

#include <stdio.h>

int main(void)
{
    char str[] = "Hello World RD13!";

    printf("Original: %s\n", str);
    printf("Reversed: %s\n", ft_strrev(str));

    return (0);
}
