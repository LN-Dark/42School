/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:44:51 by pbranco-          #+#    #+#             */
/*   Updated: 2024/11/08 16:04:18 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strichr(const char *s, int c)
{
	int	i;

	i = 0;
	if(!s)
		return (-1);
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (i);
	return (-1);
}

char	*ft_read(int fd, char *temp, int *indexreaded)
{
	char *readed;

	while (*indexreaded > 0)
    {
    	readed = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!readed)
        	return (NULL);
        *indexreaded = read(fd, readed, BUFFER_SIZE);
        if (*indexreaded == 0)
        	return (free(readed), temp);
        if (*indexreaded == -1 || *indexreaded == 0)
            return (free(readed), NULL);
        readed[*indexreaded] = '\0';
        temp = ft_strjoin(temp, readed);
        if (ft_strchr(temp, '\n'))
        	return (free(readed), temp);
        free(readed);
    }
    return (temp);
}

char	*ft_maketemp(char *temp)
{
	char *str;
	int i;

	i = 0;
	if (temp[i] == '\n')
		i++;
	while (temp[i] != '\0' && temp[i] != '\n')
	{
		i++;
	}
	if (temp[i] == '\n')
		i++;
	str = ft_strdup(temp + i);
	if (temp)
		free(temp);
	return (str);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		size;
	char	*new;

	i = 0;
	size = ft_strlen(src);
	new = malloc(sizeof(char) * size + 1);
	if (!new)
	{
		return (NULL);
	}
	while (src[i] != '\0')
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*temp2;
	static char	*temp;
	int indexreaded;
	int index;
	
	line = NULL;
	indexreaded = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!temp)
		temp = NULL;
	temp = ft_read(fd, temp, &indexreaded);
	if (ft_strichr(temp, '\n') >= 0)
		index = ft_strichr(temp, '\n');
	else if (ft_strichr(temp, '\0') >= 0)
		index = ft_strichr(temp, '\0');
	else
		return (NULL);
	if (ft_strichr(temp, '\n') != -1)
	{
		temp2 = ft_strndup(temp, index + 1);
		line = ft_strjoin(line, temp2);
		free(temp2);
	}
	else
	{
		line = ft_strjoin(line, temp);
		if (indexreaded == 0 && temp)
		{
			free(temp);
			temp = NULL;
		}
		return (line);
	}
	temp = ft_maketemp(temp);
	if (!line)
		return (NULL);
	return (line);
}
	
