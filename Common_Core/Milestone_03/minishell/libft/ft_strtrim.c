/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:56:01 by dfrincu           #+#    #+#             */
/*   Updated: 2025/05/27 17:12:13 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	if (start == end)
		return (ft_strdup(""));
	result = malloc(end - start + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1 + start, end - start + 1);
	return (result);
}
/*#include <stdio.h>
#include "libft.h"

int main(void)
{
    char *frase = "!!!Hola Mundo!!!";
    char *quitar = "!";
    char *resultado;

    resultado = ft_strtrim(frase, quitar);
    printf("Original: '%s'\n", frase);
    printf("Recortada: '%s'\n", resultado);

    free(resultado);
    return 0;
}*/
