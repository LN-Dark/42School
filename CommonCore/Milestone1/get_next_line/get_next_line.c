/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:44:51 by pbranco-          #+#    #+#             */
/*   Updated: 2024/11/12 09:05:31 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strichr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (i);
	return (-1);
}

char	*ft_read(int fd, char *temp)
{
	char	*readed;
	int		indexreaded;

	indexreaded = 1;
	while (indexreaded > 0)
	{
		readed = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!readed)
			return (NULL);
		indexreaded = read(fd, readed, BUFFER_SIZE);
		if (indexreaded == -1)
			return (free(readed), NULL);
		if (indexreaded == 0)
			return (free(readed), temp);
		readed[BUFFER_SIZE] = '\0';
		temp = ft_strjoin(temp, readed);
		free(readed);
	}
	return (temp);
}

char	*ft_maketemp(char *temp)
{
	char	*str;
	int		i;

	i = 0;
	while (temp[i])
	{
		if ((temp[i] == '\n' && temp[i + 1] == '\n') || temp[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	str = ft_strdup(temp + i);
	if (temp)
		free(temp);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;
	char		*temp2;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!temp)
		temp = NULL;
	if (ft_strnlen(temp, 0, 1) <= 0)
		temp = ft_read(fd, temp);
	if (ft_strnlen(temp, 0, 1) == 0)
		return (free(temp), NULL);
	if (ft_strichr(temp, '\n') >= 0)
		temp2 = ft_strndup(temp, ft_strichr(temp, '\n') + 1);
	else if (ft_strichr(temp, '\0') >= 0)
		temp2 = ft_strndup(temp, ft_strichr(temp, '\0'));
	else
		return (NULL);
	line = ft_strjoin(line, temp2);
	temp = ft_maketemp(temp);
	if (!line)
		return (free(temp2), NULL);
	return (free(temp2), line);
}

char	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	b;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (count > SIZE_MAX / size)
		return (NULL);
	b = count * size;
	p = malloc(b);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, b);
	return (p);
}
