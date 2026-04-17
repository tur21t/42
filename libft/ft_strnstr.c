/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:36:13 by dfrincu           #+#    #+#             */
/*   Updated: 2025/05/27 14:31:02 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && little[j] && (i + j) < len
			&& big[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
/*#include <stdio.h>
int main(void)
{
	const char	*big = "Hello Evaluator";
	const char	*little = "Evaluator";
	char		*result;

	result = ft_strnstr(big, little, 15);
	if (result)
		printf("Found: %s\n", result);
	else
		printf("Not found.\n");

	result = ft_strnstr(big, "Network", 10);
	if (result)
		printf("Found: %s\n", result);
	else
		printf("Not found.\n");

	result = ft_strnstr(big, "", 5);
	if (result)
		printf("Found empty string: %s\n", result);
	else
		printf("Empty string not found.\n");

	return (0);
}*/
