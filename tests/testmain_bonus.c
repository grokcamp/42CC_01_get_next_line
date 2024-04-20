/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampbel <gcampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 23:15:23 by gcampbel          #+#    #+#             */
/*   Updated: 2024/04/19 17:54:22 by gcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line;

	fd1 = open("bossofthisgym.txt", O_RDONLY);
	fd2 = open("octagon.txt", O_RDONLY);
	/*
	printf("\n*****Now Testing: \"bossofthisgym.txt\"*****\n\n");
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	printf("\n*****Now Testing: \"octagon.txt\"*****\n\n");
	while ((line = get_next_line(fd2)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	*/
	printf("\n*****Now Testing: File Switching*****\n\n");
	line = "";
	int i = 1;
	printf("FD's are on: %d, %d\n\n", fd1, fd2);
	while (line)
	{
		line = (get_next_line(fd1));
		printf("test %d   =   %s\n", i, line);
		free(line);
		line = (get_next_line(fd2));
		printf("test %d   =   %s\n", i, line);
		free(line);
		i++;
	}

	close(fd1);
	close(fd2);
	return (0);
}

