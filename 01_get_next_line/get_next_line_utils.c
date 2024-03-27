/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampbel <gcampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:06:32 by gcampbel          #+#    #+#             */
/*   Updated: 2024/03/27 18:19:45 by gcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str);
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	size_t	l1;
	size_t	l2;
	char	*out;

	l1 = ft_strlen(s1);
	if (!n)
		l2 = n;
	else
		l2 = ft_strlen(s2);
	out = (char *)malloc((l1 + l2 + 1) * sizeof(char));
	if (!out)
		return (NULL);
	while (s1[l1])
	{
		out[l1] = s1[l1];
		l1++;
	}
	while (s2[l2])
	{
		out[l1 + l2] = s2[l2];
		l2++;
	}
	out[l1 + l2] = '\0';
	return (out);
}

/*
char	*ft_strnjoin(char *s1, char *s2, int n)
{
	size_t	c1;
	size_t	c2;
	char	*out;

	c1 = ft_strlen(s1);
	if (!n)
		c2 = ft_strlen(s2);
	else
		c2 = ft_strlen(s2);
	out = (char *)malloc((c1 + c2 + 1) * sizeof(char));
	if (!out)
		return (free(s1), NULL);
	out[c1 + c2] = '\0';
	while (c2--)
		out[c1 + c2] = s2[c2];
	while (c1--)
		out[c1] = s1[c1];
	free(s1);
	return (out);
}
*/