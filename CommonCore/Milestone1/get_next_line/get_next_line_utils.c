/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:45:02 by pbranco-          #+#    #+#             */
/*   Updated: 2024/11/04 14:56:37 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strnlen(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while ((str[i] != '\0' && str[i] != c))
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c || !c)
		return ((char *) s + i);
	return (NULL);
}

char	*ft_strndup(const char *s, int lenght)
{
	int		i;
	int		j;
	char	*str;

	j = lenght;
	str = malloc(sizeof(char) * (j + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;
	char	*str;

	i = 0;
	j = 0;
	len1 = ft_strnlen(s1, '\0');
	len2 = ft_strnlen(s2, '\0');
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (0);
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < len2)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*s;

	s = (unsigned char *)str;
	while (n--)
	{
		*s++ = '\0';
	}
}
