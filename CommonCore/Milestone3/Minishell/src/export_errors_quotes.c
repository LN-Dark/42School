/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_errors_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:43:53 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 11:35:31 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	errors_with_quotes3_1_1(char *input, size_t *i, int *error, int *found)
{
	if (input[*i] && input[*i] == '"')
	{
		(*i)++;
		while (input[*i] && input[(*i)++] != '"')
		{
			if (!ft_isalpha(input[*i]) && input[*i] != '_' && \
			input[*i] != '"' && input[*i] != '\'' && input[*i] != '+' && \
			!ft_isdigit(input[*i]) && !(*found) && input[*i] != '$')
			{
				(*error)++;
				if (input[*i])
					(*i)++;
			}
			if (input[*i] && !found && input[*i] == '=')
			{
				found++;
				if (input[*i])
					(*i)++;
			}
		}
		if (input[*i] && input[*i] == '"')
			(*i)++;
	}
}

void	errors_with_quotes3_1(char *input, size_t *i, int *error, int *found)
{
	if (input[*i] && input[*i] == '\'')
	{
		(*i)++;
		while (input[*i] && input[(*i)++] != '\'')
		{
			if (!ft_isalpha(input[*i]) && input[*i] != '_' && \
			input[*i] != '"' && input[*i] != '\'' && input[*i] != '+' && \
			!ft_isdigit(input[*i]) && !(*found) && input[*i] != '$')
			{
				(*error)++;
				if (input[*i])
					(*i)++;
			}
			if (input[*i] && !found && input[*i] == '=')
			{
				found++;
				if (input[*i])
					(*i)++;
			}
		}
		if (input[*i] && input[*i] == '\'')
			(*i)++;
	}
	errors_with_quotes3_1_1(input, i, error, found);
}

void	errors_with_quotes2_1(char *input, size_t *i, int *found, int *error)
{
	if (input[*i] == '=')
	{
		*found = 1;
		if (input[*i])
			(*i)++;
	}
	if (!(ft_isalpha(input[*i])) && input[*i] != '_' && input[*i] != '"' && \
	input[*i] != '\'' && !(ft_isdigit(input[*i])) && !(*found) && \
	input[*i] != '\0' && input[*i] != '$' && input[*i] != '+')
	{
		(*error)++;
		if (input[*i])
			(*i)++;
	}
}

void	errors_with_quotes2(char *input, char **new_input, size_t *i, size_t *j)
{
	int		found;
	int		error;
	size_t	l;

	error = 0;
	found = 0;
	l = *i;
	while (input[*i] && input[*i] != ' ')
	{
		errors_with_quotes2_1(input, i, &found, &error);
		quotes3_1(input, i, &error, &found);
		quotes3_2(input, i, &found);
	}
	if (error)
		print_error_export(i, l, input);
	else
	{
		while (l < (*i))
			(*new_input)[(*j)++] = input[l++];
	}
}

char	*errors_with_quotes(char *input, t_ms **ms)
{
	size_t	i;
	char	*new_input;
	size_t	j;

	i = 0;
	j = 0;
	new_input = malloc(sizeof(char) * (ft_strlen(input) + 10));
	while (input[i])
	{
		if (input[i] && input[i] == ' ')
		{
			while (input[i] && input[i] == ' ')
				i++;
		}
		if (ft_isalpha(input[i]) || input[i] == '\'' || input[i] == '"' || \
		input[i] == '_' || input[i] == '$')
			errors_with_quotes2(input, &new_input, &i, &j);
		else
			catch_errors(input, &i);
		new_input[j++] = ' ';
	}
	free(input);
	new_input[j] = '\0';
	(void)ms;
	return (new_input);
}
