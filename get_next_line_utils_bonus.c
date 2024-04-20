/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampbel <gcampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 22:15:12 by gcampbel          #+#    #+#             */
/*   Updated: 2024/04/20 16:18:12 by gcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* strlen finds the length of a string, returned as an int*/

int	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

/* modjoin is a modified strnjoin, where if `n` does not exist,
it takes the value of s2 as `n` (for `nlfinder`), and it includes
a `free` operation to handle the `out` passed from `get_next_line`
for subsequent/repeat allocations to prevent leaks.*/

char	*ft_modjoin(char *s1, char *s2, int n)
{
	size_t	l1;
	size_t	l2;
	char	*out;

	l1 = ft_strlen(s1);
	if (n)
		l2 = n;
	else
		l2 = ft_strlen(s2);
	out = (char *)malloc((l1 + l2 + 1) * sizeof(char));
	if (!out)
		return (free(s1), NULL);
	out[l1 + l2] = '\0';
	while (l2--)
		out[l1 + l2] = s2[l2];
	while (l1--)
		out[l1] = s1[l1];
	free(s1);
	return (out);
}

/* modmove is a modified `memmove` that takes into account the
`BUFFER_SIZE` defined either in the `.h` file or on compilation,
in order to prevent undefined behavior by searching beyond the
bounds of the declared buffer.*/

void	*ft_modmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (!dest && !src)
		return (NULL);
	while (++i < BUFFER_SIZE)
	{
		if (n && i < BUFFER_SIZE - n)
			((char *)dest)[i] = ((char *)src)[i];
		else
			((char *)dest)[i] = '\0';
	}
	return (dest);
}
/* original memmove doesn't check for buffer overflow!
	needs a `BUFFER_SIZE - n` value for safety, see above
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*csrc;
	char	*cdst;

	csrc = (char *)src;
	cdst = (char *)dest;
	if (!dest && !src)
		return (NULL);
	if (dest <= src)
	{
		i = 0;
		while (i < n)
		{
			cdst[i] = csrc[i];
			i++;
		}
	}
	else if (dest > src)
	{
		i = n;
		while (i--)
			cdst[i] = csrc[i];
	}
	return (dest);
}
*/
