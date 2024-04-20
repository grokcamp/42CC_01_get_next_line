/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcampbel <gcampbel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 22:15:02 by gcampbel          #+#    #+#             */
/*   Updated: 2024/04/20 16:18:10 by gcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* definitions */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* bonus definition included for modified GNL fn */
# ifndef MAX_FD
#  define MAX_FD 1024
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
