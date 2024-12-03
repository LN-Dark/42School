/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:44:51 by pbranco-          #+#    #+#             */
/*   Updated: 2024/11/14 11:30:39 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strichr_gnl(const char *s, int c)
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

char	*ft_read_gnl(int fd, char *temp)
{
	char	*readed;
	int		indexreaded;

	indexreaded = 1;
	readed = ft_calloc_gnl((BUFFER_SIZE + 1), sizeof(char));
	while (indexreaded > 0 && ft_strichr_gnl(temp, '\n') <= 0)
	{
		if (!readed)
			return (NULL);
		indexreaded = read(fd, readed, BUFFER_SIZE);
		if (indexreaded == -1)
		{
			ft_free_gnl(&readed);
			ft_free_gnl(&temp);
			return (NULL);
		}
		if (indexreaded == 0)
			return (ft_free_gnl(&readed), temp);
		readed[indexreaded] = '\0';
		temp = ft_strjoin_gnl(temp, readed);
	}
	ft_free_gnl(&readed);
	return (temp);
}

char	*ft_maketemp_gnl(char *temp)
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
	str = ft_strdup_gnl(temp + i);
	ft_free_gnl(&temp);
	if (ft_strnlen_gnl(str, 0, 1) == 0)
		return (ft_free_gnl(&str), NULL);
	else
		return (str);
	return (NULL);
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
	temp = ft_read_gnl(fd, temp);
	if (!temp)
		return (NULL);
	if (ft_strnlen_gnl(temp, 0, 1) == 0)
		return (NULL);
	if (ft_strichr_gnl(temp, '\n') >= 0)
		temp2 = ft_strndup_gnl(temp, ft_strichr_gnl(temp, '\n') + 1);
	else if (ft_strichr_gnl(temp, '\0') >= 0)
		temp2 = ft_strndup_gnl(temp, ft_strichr_gnl(temp, '\0'));
	else
		return (NULL);
	line = ft_strjoin_gnl(line, temp2);
	temp = ft_maketemp_gnl(temp);
	if (!line)
		return (ft_free_gnl(&temp2), NULL);
	return (ft_free_gnl(&temp2), line);
}

char	*ft_calloc_gnl(size_t count, size_t size)
{
	char	*p;
	size_t	b;
	int		i;

	i = 0;
	if (count == 0 || size == 0)
		return (0);
	if (count > SIZE_MAX / size)
		return (NULL);
	b = count * size;
	p = malloc(b);
	if (p == NULL)
		return (NULL);
	while (b--)
	{
		p[i] = '\0';
		i++;
	}
	return (p);
}
