/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampbel <gcampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:25:52 by gcampbel          #+#    #+#             */
/*   Updated: 2024/04/20 16:18:07 by gcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* definitions */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* includes */
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/* get_next_line.c prototypes */
char	*get_next_line(int fd);
int		nlfinder(char *str);
int		buffcheck(int fd, char *buff);

/* get_next_line_utils.c prototypes */
int		ft_strlen(char *str);
char	*ft_modjoin(char *s1, char *s2, int n);
void	*ft_modmove(void *dest, const void *src, size_t n);

#endif
