/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:43:17 by akuburas          #+#    #+#             */
/*   Updated: 2023/12/05 11:32:15 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_line_allocator(int fd, char *line_storage)
{
	char	*buffer;
	int		read_bytes;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(line_storage);
		return (NULL);
	}
	read_bytes = 1;
	while (!ft_strchr(line_storage, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free (buffer);
			free (line_storage);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		line_storage = ft_strjoin(line_storage, buffer);
	}
	free(buffer);
	return (line_storage);
}

char	*ft_give_line(char *line_storage)
{
	char	*line;
	char	*newline_pos;
	size_t	line_length;

	newline_pos = ft_strchr(line_storage, '\n');
	if (!newline_pos)
		return (NULL);
	line_length = newline_pos - line_storage + 1;
	line = (char *)malloc(line_length * sizeof(char));
	if (!line)
		return (NULL);
	ft_memcpy(line, line_storage, line_length -1);
	line[line_length -1] = '\0';
	return (line);
}

static char	*ft_remove_line(char *line_storage)
{
	char	*newline_pos;
	size_t	remaining_length;

	newline_pos = ft_strchr(line_storage, 'n');
	if (!newline_pos)
		return (NULL);
	remaining_length =ft_strlen(newline_pos + 1);
	ft_memcpy(line_storage, newline_pos + 1, remaining_length +1);
	return (line_storage);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*line_storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_storage = ft_line_allocator(fd, line_storage);
	if (!line_storage)
		return (NULL);
	line = ft_give_line(line_storage);
	if (!line)
	{
		free(line_storage);
		return (NULL);
	}
	line_storage = ft_remove_line(line_storage);
}
