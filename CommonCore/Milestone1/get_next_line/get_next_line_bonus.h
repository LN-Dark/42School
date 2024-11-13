/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:45:16 by pbranco-          #+#    #+#             */
/*   Updated: 2024/11/13 10:04:17 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MAX_FD 1024

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strndup(const char *s, int i);
char	*ft_read(int fd, char *temp);
char	*ft_maketemp(char *temp);
char	*ft_strdup(char *src);
char	*ft_calloc(size_t count, size_t size);
int		ft_strichr(const char *s, int c);
int		ft_strnlen(const char *str, char c, int type);
void	ft_free(char **temp);

#endif
