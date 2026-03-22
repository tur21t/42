/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:36:59 by dfrincu           #+#    #+#             */
/*   Updated: 2025/05/23 14:54:14 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	ch;

	last = NULL;
	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			last = (char *)s;
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (last);
}
/*#include <stdio.h>
int	main(void)
{
	char str[] = "Hello world!";
	printf("Original: %s\n", str);
	printf("ft_strrchr 'o': %s\n", ft_strrchr(str, 'o'));
	printf("ft_strrchr 'z': %s\n", ft_strrchr(str, 'z'));
	printf("ft_strrchr '\\0': %s\n", ft_strrchr(str, '\0'));
	return (0);
}*/
