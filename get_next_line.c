/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampbel <gcampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:31:10 by gcampbel          #+#    #+#             */
/*   Updated: 2024/04/20 16:18:08 by gcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* `nlfinder` looks for the index within the string where
a newline ('\n') occurs and returns the index of the next char*/

int	nlfinder(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
	{
		if (str[i] == '\n')
			return (i + 1);
	}
	return (0);
}

/* buffcheck is a boolean t/f checker that checks to see if anything
exists inside the buffer -- 0 for empty, nonzero for populated */

int	buffcheck(int fd, char *buff)
{
	if (buff[0])
		return (1);
	if (read(fd, buff, BUFFER_SIZE) > 0)
		return (1);
	return (0);
}

/* GNL first initializes `out`, then loops to ensure we're not
starting on a newline AND that something exists inside the buffer.

It then sets the counter `nl` to the index `nlfinder` discovers,
and sets the string `out` to the union of its prev value and
the buffer for `nl` chars.
^ (e.g. a 'max len to join' of the index found by nlfinder)

If `out` failed malloc, it exits `NULL`.

Otherwise, the remainder of the current buffer, beginning after
the newline index (`&buff[nl]`), is moved to the beginning
of the buffer via `modmove`.
(No, I'm not daring enough to bitshift yet, sue me.)

`return(out)` only occurs when there is
no newline AND buffcheck returns 0 (empty or '\0'),
indicating the end of the line, OR the end of the
text in `fd` (where no '\n' exists).*/

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*out;
	int			nl;

	out = NULL;
	while ((!nlfinder(out)) && buffcheck(fd, (char *)buff) > 0)
	{
		nl = nlfinder(buff);
		out = ft_modjoin(out, buff, nl);
		if (!out)
			return (NULL);
		ft_modmove(buff, &buff[nl], nl);
	}
	return (out);
}
