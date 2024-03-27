/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampbel <gcampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:25:52 by gcampbel          #+#    #+#             */
/*   Updated: 2024/03/27 18:19:55 by gcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* definitions */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE = 42
# endif

/* includes */
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/* get_next_line.c prototypes */
char	*get_next_line(int fd);

/* get_next_line_utils.c prototypes */
int		ft_strlen(char *str);
char	*ft_strnjoin(char *s1, char *s2, int n);

#endif
