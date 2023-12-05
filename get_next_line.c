/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:43:17 by akuburas          #+#    #+#             */
/*   Updated: 2023/12/05 08:23:21 by akuburas         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	char		*line;
	static char	*line_storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_storage = ft_line_allocator(fd, line_storage);
}
