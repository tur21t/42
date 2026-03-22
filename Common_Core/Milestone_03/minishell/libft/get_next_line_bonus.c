/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfrincu <dfrincu@student.42barcelona.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:57:11 by dfrincu           #+#    #+#             */
/*   Updated: 2025/07/11 10:32:52 by dfrincu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*rests[MAX_FD];
	char		*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	rests[fd] = read_and_join(fd, rests[fd]);
	if (!rests[fd] || !*rests[fd])
	{
		free(rests[fd]);
		rests[fd] = NULL;
		return (NULL);
	}
	line = extract_line(rests[fd]);
	if (!line)
	{
		free(rests[fd]);
		rests[fd] = NULL;
		return (NULL);
	}
	rests[fd] = update_rest(rests[fd]);
	return (line);
}

char	*read_and_join(int fd, char *rest)
{
	char	*buffer;
	char	*tmp;
	long	bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while ((!rest || !gnl_strchr(rest, '\n')) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		tmp = rest;
		rest = gnl_strjoin(rest, buffer);
		free(tmp);
	}
	free(buffer);
	if (bytes_read < 0 || (rest && !*rest))
	{
		free(rest);
		return (NULL);
	}
	return (rest);
}

char	*extract_line(char *rest)
{
	int		i;
	char	*line;

	if (!rest || !*rest)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (rest[i] == '\n')
		i++;
	line = gnl_substr(rest, 0, i);
	return (line);
}

char	*update_rest(char *rest)
{
	char	*new_rest;
	char	*newline_ptr;
	int		i;

	if (!rest || !*rest)
		return (NULL);
	newline_ptr = gnl_strchr(rest, '\n');
	if (!newline_ptr)
	{
		free(rest);
		return (NULL);
	}
	i = newline_ptr - rest + 1;
	if (!rest[i])
	{
		free(rest);
		return (NULL);
	}
	new_rest = gnl_strdup(rest + i);
	free(rest);
	return (new_rest);
}

size_t	gnl_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	if (!src)
		src = "";
	while (src[src_len])
		src_len++;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}
