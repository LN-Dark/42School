/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_quotes5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:45:00 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:45:00 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_i_export(char *input, size_t *i)
{
	if (*i > 0)
	{
		if (input[(*i)--])
		{
			while (*i > 0 && input[(*i)] != ' ')
				(*i)--;
		}
	}
}

size_t	export_quotes5_3(char *input, size_t *i, t_ms **ms, size_t h)
{
	char	*str2;
	char	*str3;

	(*ms)->y = 0;
	str2 = malloc(sizeof(char) * (ft_strlen(input)));
	while (input[(*i)] && input[(*i)] != ' ' && \
	input[(*i)] != '/' && input[(*i)] != '"')
		str2[((*ms)->y)++] = input[(*i)++];
	str2[(*ms)->y] = '\0';
	str2 = expand_heredoc(ms, 1, str2);
	(*ms)->str_exp[h] = '\0';
	str3 = ft_strdup((*ms)->str_exp);
	free((*ms)->str_exp);
	(*ms)->y = 0;
	h = 0;
	(*ms)->str_exp = malloc(sizeof(char) * \
	(ft_strlen(input) + ft_strlen(str3) + 1));
	while (str3[(*ms)->y])
		(*ms)->str_exp[h++] = str3[((*ms)->y)++];
	(*ms)->y = 0;
	while (str2[(*ms)->y])
		(*ms)->str_exp[h++] = str2[((*ms)->y)++];
	free(str2);
	free(str3);
	return (h);
}

size_t	export_quotes5_2(char *input, size_t *i, t_ms **ms, size_t h)
{
	(*i)++;
	while (input[(*i)] != '$' && input[(*i)] != '"')
		(*ms)->str_exp[h++] = input[(*i)++];
	if (input[(*i)] == '"')
		(*i)++;
	else
		h = export_quotes5_3(input, i, ms, h);
	return (h);
}

void	export_quotes5__(char *input, size_t *i, t_ms **ms)
{
	(*i)++;
	while (input[*i] != '\'')
		(*ms)->str_exp[((*ms)->c)++] = input[(*i)++];
	(*i)++;
}

char	*export_quotes5(char *input, size_t *i, t_ms **ms)
{
	(*ms)->c = 0;
	get_i_export(input, i);
	(*ms)->str_exp = malloc(sizeof(char) * (ft_strlen(input) + 1));
	while (input[*i] == ' ')
		(*i)++;
	while (input[*i])
	{
		if (input[*i] != '\'' && input[*i] != '"')
		{
			while (input[*i] && input[*i] != '\'' && input[*i] != '"' && \
			input[*i] != ' ')
				(*ms)->str_exp[((*ms)->c)++] = input[(*i)++];
			break ;
		}
		if (input[*i] == '\'')
			export_quotes5__(input, i, ms);
		if (input[*i] == '"')
			((*ms)->c) = export_quotes5_2(input, i, ms, ((*ms)->c));
	}
	(*ms)->str_exp[((*ms)->c)] = '\0';
	return ((*ms)->str_exp);
}
