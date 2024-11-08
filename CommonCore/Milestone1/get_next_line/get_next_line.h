/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:45:16 by pbranco-          #+#    #+#             */
/*   Updated: 2024/11/08 14:27:42 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int	ft_strlen(const char *str);
char	*ft_strndup(const char *s, int i);
int	ft_strichr(const char *s, int c);
char	*ft_read(int fd, char *temp, int *indexreaded);
char	*ft_maketemp(char *temp);
int	ft_strnlen(const char *str, char c);
char	*ft_strchr(char *str, char c);
char	*ft_strdup(char *src);

#endif
