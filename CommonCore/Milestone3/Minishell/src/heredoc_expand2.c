/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expand2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:53:49 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:40:56 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

char	*n_str_heredoc2(char **str2, size_t	i)
{
	char	*n_str;
	char	*n_str2;

	n_str2 = ft_strdup(str2[0]);
	while (str2[i])
	{
		n_str = ft_strjoin(n_str2, str2[i]);
		free(n_str2);
		n_str2 = n_str;
		i++;
	}
	return (n_str2);
}

char	*n_str_heredoc(char **str2, int n)
{
	size_t	i;
	char	*n_str;
	char	*n_str2;

	i = 1;
	if (!n)
	{
		n_str2 = ft_strjoin(str2[0], "\n");
		while (str2[i])
		{
			n_str = ft_strjoin(n_str2, str2[i]);
			free(n_str2);
			n_str2 = ft_strjoin(n_str, "\n");
			free(n_str);
			i++;
		}
	}
	else
		n_str2 = n_str_heredoc2(str2, i);
	return (n_str2);
}

int	get_checkhere(t_ms **ms, char *n_str, size_t *i)
{
	int	check;

	check = 0;
	while ((*ms)->envp[*i])
	{
		if (ft_strstr_1((*ms)->envp[*i], n_str) != NULL && n_str[0] != '\0')
		{
			check = 1;
			break ;
		}
		(*i)++;
	}
	return (check);
}

char	*trim_f_start(char *s1, char *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		j++;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	i++;
	str = (char *)ft_calloc((j - i + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	str[j] = '\0';
	return (str);
}

char	*get_var(char *n_str, t_ms **ms)
{
	int		check;
	char	*str;
	char	*str2;
	size_t	i;

	i = 0;
	check = get_checkhere(ms, n_str, &i);
	if (check)
	{
		str = ft_strdup((*ms)->envp[i]);
		str2 = trim_f_start(str, n_str);
		free(str);
		str = ft_strtrim(str2, "=");
		free(str2);
	}
	else
		str = NULL;
	return (free(n_str), str);
}
