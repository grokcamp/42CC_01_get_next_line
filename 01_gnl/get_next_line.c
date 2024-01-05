/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampbel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:23:48 by gcampbel          #+#    #+#             */
/*   Updated: 2024/01/06 00:20:10 by gcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reader(int fd)
{
	int	byteread;
	char	*buffcorrell;
	static int	count;

	count = 1;
	printf("calloc#[%d]---", count++);
	buffcorrell = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffcorrell == NULL)
		return (NULL);
	byteread = read(fd, buffcorrell, BUFFER_SIZE);
	if (byteread <= 0)
	{
		free (buffcorrell);
		return (NULL);
	}
	return (buffcorrell);
}

char	*get_next_line(int fd)
{
	char	*buffalouie;

	buffalouie = reader(fd);
	return (buffalouie);
}

/* Test Main */
int	main(void)
{
	int	fd;
	char	*nl;
	int	count = 0;

	fd = open("bossofthisgym.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Read machine broke");
		return (1);
	}
	while (1)
	{
		nl = get_next_line(fd);
		if (nl == NULL)
			break ;
		count++;
		printf("[%d]:%s\n", count, nl);
		free(nl);
		nl = NULL;
	}
	close(fd);
	return (0);
}
