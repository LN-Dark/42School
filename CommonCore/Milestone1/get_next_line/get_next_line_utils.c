/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:45:02 by pbranco-          #+#    #+#             */
/*   Updated: 2024/11/08 15:49:23 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
    size_t  i;
    size_t  j;
    size_t  len1;
    size_t  len2;
    char    *str;

    if (!s2 || !*s2)
        return (NULL);
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    str = malloc(sizeof(char) * (len1 + len2 + 1));
    if (!str)
        return (free(str), NULL);
    i = 0;
    while (i < len1) {
        str[i] = s1[i];
        i++;
    }
    j = -1;
    while (++j < len2) {
        str[i + j] = s2[j];
    }
    str[i + j] = '\0';
    return (free(s1), str);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strnlen(const char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while ((str[i] && str[i] != (int)c))
		i++;
	return (i);
}

char	*ft_strndup(const char *s, int lenght)
{
	int		i;
	char	*str;

	str = malloc(sizeof(char) * (lenght + 1));
	if (str == NULL)
		return (free(str), NULL);
	if (lenght == 0)
		return (free(str), NULL);
	i = 0;
	while (i < lenght)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(char *str, char c)
{
	int	i;
	int	size;

	if (!str)
		return (NULL);
	i = 0;
	size = ft_strnlen(str, '\0');
	while (str[i])
	{
		if (str[i] == c)
			break ;
		i++;
	}
	if (c == '\0')
		return (str + i);
	if (size <= i)
		return (NULL);
	return (str + i);
}