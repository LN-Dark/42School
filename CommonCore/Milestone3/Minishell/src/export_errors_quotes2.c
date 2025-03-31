/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_errors_quotes2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:44:04 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:44:04 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	catch_errors2quotes1(char *input, char **str, size_t *p)
{
	if (input[*p] == '\'')
	{
		(*str)[*p] = input[*p];
		(*p)++;
		while (input[(*p)++] != '\'')
			(*str)[*p] = input[*p];
		if (input[*p] == '\'')
		{
			(*str)[*p] = input[*p];
			(*p)++;
		}
	}
	if (input[*p] == '"')
	{
		(*str)[*p] = input[*p];
		(*p)++;
		while (input[(*p)++] != '"')
			(*str)[*p] = input[*p];
		if (input[*p] == '"')
		{
			(*str)[*p] = input[*p];
			(*p)++;
		}
	}
}

void	catch_errors2quotes(char *input, size_t *i, char **str, size_t p)
{
	while (input[p])
	{
		catch_errors2quotes1(input, str, &p);
		if (input[p] == ' ')
			break ;
		if (input[p] != '"' && input[p] != '\'')
		{
			(*str)[p] = input[p];
			p++;
		}
	}
	*i = p;
	(*str)[p] = '\0';
	ft_put_error(ERROR_EXP_P, "%s", *str);
	free(*str);
}

void	catch_errors2(char *input, size_t *i, char **str, size_t j)
{
	size_t	p;
	char	*str2;

	p = *i;
	while (input[*i] && input[*i] != ' ')
		(*str)[j++] = input[(*i)++];
	(*str)[j] = '\0';
	if (ft_strchr(*str, '\'') || ft_strchr(*str, '"'))
	{
		free(*str);
		str2 = malloc(sizeof(char) * (ft_strlen(input) + 1));
		catch_errors2quotes(input, i, &str2, p);
	}
	else
	{
		ft_put_error(ERROR_EXP_P, "%s", *str);
		free(*str);
	}
}

void	catch_errors(char *input, size_t *i)
{
	char	*str;
	size_t	j;

	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(input) + 1));
	if (input[*i] == '=' && input[*i + 1] && input[*i + 1] == ' ')
	{
		(*i)++;
		ft_putstr_fd(ERROR_EXP_M, 2);
		free(str);
	}
	else
		catch_errors2(input, i, &str, j);
}
