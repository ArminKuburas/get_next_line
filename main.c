/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:41:18 by akuburas          #+#    #+#             */
/*   Updated: 2023/12/05 12:36:01 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd = open("test.txt", O_RDONLY);
	char	*line;

	line = get_next_line(fd);
	while (line)
	{

		printf("%s", line);
		free(line);
		line =  get_next_line(fd);
	}
	close(fd);
	return (0);
}
