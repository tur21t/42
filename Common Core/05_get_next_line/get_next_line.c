/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmtur <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:42:58 by dmtur             #+#    #+#             */
/*   Updated: 2025/08/19 22:33:56 by dmtur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

static int	find_newline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*extract_line(char **storage, int nl_index)
{
	char	*line;
	char	*rest;
	int		len;

	if (nl_index >= 0)
	{
		line = ft_strndup(*storage, nl_index + 1);
		len = ft_strlen(*storage + nl_index + 1);
		rest = ft_strndup(*storage + nl_index + 1, len);
		free(*storage);
		*storage = rest;
	}
	else
	{
		line = ft_strndup(*storage, ft_strlen(*storage));
		free(*storage);
		*storage = NULL;
	}
	return (line);
}

static int	append_buffer(char **storage, char *buffer)
{
	char	*tmp;

	if (!*storage)
		*storage = ft_strndup(buffer, ft_strlen(buffer));
	else
	{
		tmp = ft_strjoin(*storage, buffer);
		free(*storage);
		*storage = tmp;
	}
	return (0);
}

static int	read_into_storage(int fd, char **storage)
{
	ssize_t	bytes;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	bytes = 1;
	while (bytes > 0 && find_newline(*storage) == -1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes > 0)
		{
			buffer[bytes] = '\0';
			append_buffer(storage, buffer);
		}
	}
	free(buffer);
	if (bytes < 0)
		return (-1);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	int			nl_index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read_into_storage(fd, &storage) == -1)
		return (NULL);
	if (!storage || *storage == '\0')
	{
		free(storage);
		storage = NULL;
		return (NULL);
	}
	nl_index = find_newline(storage);
	return (extract_line(&storage, nl_index));
}

#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc != 2)
	{
		printf("note21t: Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
