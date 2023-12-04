/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:43:17 by akuburas          #+#    #+#             */
/*   Updated: 2023/12/04 15:18:20 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_line_allocator(int fd, char *line_storage)
{
	char	*buffer;
	int		bytes;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(line_storage);
		return (NULL);
	}
	bytes = 1;
	while(strchr)
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*line_storage;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_storage = ft_line_allocator(fd, line_storage);
}
