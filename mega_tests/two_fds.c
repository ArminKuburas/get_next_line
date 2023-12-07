/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_fds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:05:03 by akuburas          #+#    #+#             */
/*   Updated: 2023/12/07 17:08:08 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

int	main(void)
{
	int fd1, fd2;
	char *line1, *line2;

	fd1 = open("sm.txt", O_RDONLY);
	fd2 = open("lm.txt", O_RDONLY);
	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	while (line1 != NULL || line2 != NULL)
	{
		if (line1)
		{
			printf("FD1: %s\n", line1);
			free(line1);
		}
		if (line2)
		{
			printf("FD2: %s\n", line2);
			free(line2);
		}
	}

	close(fd1);
	close(fd2);

	return (0);
}