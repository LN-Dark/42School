/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:44:51 by pbranco-          #+#    #+#             */
/*   Updated: 2024/11/04 14:54:32 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*s;

	s = (unsigned char *)str;
	while (n--)
	{
		*s++ = '\0';
	}
}

char	*ft_free(char *buffer, char *left_c)
{
	free(buffer);
	free(left_c);
	return (NULL);
}

static char	*ft_set(char *line)
{
	char	*rest;

	rest = ft_strndup((line + ft_strnlen(line, '\n')
				+ 1), (ft_strnlen(line, '\0') - ft_strnlen(line, '\n')));
	free (line);
	if (!rest)
		return (NULL);
	return (rest);
}

static char	*ft_fill_line(int fd, char *temp)
{
	ssize_t	read_break;
	char	*temp_buff;

	read_break = 1;
	temp_buff = ft_calloc(BUFFER + 1, sizeof(char));
	if (!temp_buff)
		return (NULL);
	while (read_break > 0 && !ft_strchr(temp_buff, '\n'))
	{
		read_break = read(fd, temp_buff, BUFFER);
		if (read_break == -1)
			return (ft_free(temp_buff, temp));
		temp_buff[read_break] = '\0';
		temp = ft_strjoin(temp, temp_buff);
	}
	if (*temp == '\0')
		return (ft_free(temp_buff, temp));
	free(temp_buff);
	return (temp);
}

char	*ft_get_next_line(int fd)
{
	static char	*temp;
	char		*line;

	if (fd < 0 || BUFFER <= 0)
		return (NULL);
	if (!temp)
		temp = NULL;
	temp = ft_fill_line(fd, temp);
	if (!temp)
		return (NULL);
	line = ft_strndup(temp, ft_strnlen(temp, '\n') + 1);
	if (!line)
		return (NULL);
	temp = ft_set(temp);
	if (!temp)
		free(temp);
	return (line);
}
