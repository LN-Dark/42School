/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_slash2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:41:37 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 18:45:19 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**get_i_dots(t_ms **ms, size_t *i)
{
	char	**str;

	str = ft_split((*ms)->pwd, '/');
	while (str[*i])
		(*i)++;
	return (str);
}

char	**get_j_dots(char *input, size_t *i)
{
	char	**str;

	str = ft_split(input, '/');
	while (str[*i])
		(*i)++;
	return (str);
}

char	*get_str_join(char **str3, t_ms **ms)
{
	char	*str;
	char	*str1;

	(*ms)->a = 1;
	if (str3 && str3[0] != NULL)
	{
		str1 = ft_strjoin("/", str3[0]);
		str = ft_strjoin(str1, "/");
		free(str1);
		if (str3[0] && str3[1])
		{
			while (str3[(*ms)->a])
			{
				str1 = ft_strjoin(str, str3[(*ms)->a]);
				free (str);
				str = ft_strjoin(str1, "/");
				free(str1);
				((*ms)->a)++;
			}
		}
	}
	else
		str = ft_strdup("/");
	ft_free(str3);
	return (str);
}

char	*cd_slash_dots2(t_ms **ms, char **input2, char **str)
{
	char	**n_str;
	size_t	i;

	i = (*ms)->n;
	(*ms)->a = 0;
	n_str = malloc(sizeof(char *) * ((*ms)->m + i + 1));
	while ((*ms)->a < i)
	{
		n_str[(*ms)->a] = ft_strdup(str[(*ms)->a]);
		((*ms)->a)++;
	}
	(*ms)->m = 0;
	while (input2[(*ms)->m])
	{
		while (input2[(*ms)->m] && (ft_strcmp(input2[(*ms)->m], "..") == 0 || \
		ft_strcmp(input2[(*ms)->m], ".") == 0))
			(*ms)->m++;
		if (input2[(*ms)->m])
			n_str[((*ms)->a)++] = ft_strdup(input2[(*ms)->m++]);
	}
	n_str[(*ms)->a] = 0;
	ft_free(str);
	ft_free(input2);
	return (get_str_join(n_str, ms));
}

char	*cd_slash_dots(char *input, t_ms **ms)
{
	size_t	i;
	size_t	j;
	char	**str;
	char	**input2;

	i = 0;
	j = 0;
	str = get_i_dots(ms, &i);
	if (i == 0)
		return (ft_free(str), ft_strdup("/"));
	input2 = get_j_dots(input, &j);
	if (j >= i)
		return (ft_free(str), ft_free(input2), check_it_has_more(input));
	(*ms)->a = 0;
	while (input2[(*ms)->a])
	{
		if (ft_strcmp(input2[(*ms)->a], "..") == 0)
			i--;
		((*ms)->a)++;
	}
	(*ms)->m = j;
	(*ms)->n = i;
	return (cd_slash_dots2(ms, input2, str));
}
