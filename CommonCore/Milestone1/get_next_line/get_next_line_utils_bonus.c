/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 09:45:02 by pbranco-          #+#    #+#             */
/*   Updated: 2024/11/12 16:04:13 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	if (s2)
		len2 = ft_strnlen(s2, 0, 1);
	if (s1)
		len1 = ft_strnlen(s1, 0, 1);
	str = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!str)
		return (ft_free(&s1), NULL);
	i = -1;
	while (++i < len1)
		str[i] = s1[i];
	j = -1;
	while (++j < len2)
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (ft_free(&s1), str);
}

int	ft_strnlen(const char *str, char c, int type)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (type == 0)
	{
		while ((str[i] && str[i] != (int)c))
			i++;
	}
	else
	{
		while (str[i])
			i++;
	}
	return (i);
}

char	*ft_strndup(const char *s, int lenght)
{
	int		i;
	char	*str;

	str = malloc(sizeof(char) * (lenght + 1));
	if (str == NULL)
		return (ft_free(&str), NULL);
	if (lenght == 0)
		return (ft_free(&str), NULL);
	i = 0;
	while (i < lenght)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_free(char **temp)
{
	if (temp && *temp)
	{
		free(*temp);
		*temp = NULL;
	}
}

char	*ft_strdup(char *src)
{
	int		i;
	int		size;
	char	*new;

	i = 0;
	size = ft_strnlen(src, 0, 1);
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
