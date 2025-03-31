/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_quotes4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:44:55 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:44:55 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	export_quotes3_1(char *input, t_ms **ms, size_t i)
{
	i++;
	(*ms)->exp_start = i;
	if (i > 1 && input[i - 1] == '\'' \
		&& ft_isalpha(input[i - 2]) && ft_isalpha(input[i]))
		(*ms)->exp_start = get_i(input, i);
	while (input[i] && input[i] != '\'')
		i++;
	i++;
	while (input[i] && (input[i] != ' ' || \
		input[i] != '"' || input[i] != '\''))
		i++;
	add_to_array(ms, i, input, 1);
	if (input[i])
		i++;
	(*ms)->exp_start = i;
	return (i);
}

size_t	export_quotes3_2(char *input, t_ms **ms, size_t i)
{
	i++;
	(*ms)->exp_start = i;
	if (i > 1 && input[i - 1] == '"' && ft_isalpha(input[i - 2]) \
	&& ft_isalpha(input[i]))
		(*ms)->exp_start = get_i(input, i);
	while (input[i] && input[i] != '"')
		i++;
	i++;
	while (input[i] && (input[i] != ' ' || \
		input[i] != '"' || input[i] != '\''))
		i++;
	add_to_array(ms, i, input, 2);
	if (input[i])
		i++;
	(*ms)->exp_start = i;
	return (i);
}

size_t	export_quotes3_3(char *input, t_ms **ms, size_t i)
{
	i += 2;
	while (input[i] && input[i] != '\'')
		i++;
	add_to_array(ms, i, input, 1);
	if (input[i])
		i++;
	(*ms)->exp_start = i;
	return (i);
}

size_t	export_quotes3(char *input, t_ms **ms, size_t i)
{
	if ((input[i] == '\'' && i == 0) || (input[i] == '\'' \
		&& i > 0 && input[i - 1] != '='))
		i = export_quotes3_1(input, ms, i);
	else if ((input[i] == '"' && i == 0) \
	|| (input[i] == '"' && i > 0 && input[i - 1] != '='))
		i = export_quotes3_2(input, ms, i);
	else if (input[i + 1] == '\'' && input[i] == '=')
		i = export_quotes3_3(input, ms, i);
	else if (input[i + 1] == '"' && input[i] == '=')
	{
		i += 2;
		while (input[i] && input[i] != '"')
			i++;
		add_to_array(ms, i, input, 2);
		if (input[i])
			i++;
		(*ms)->exp_start = i;
	}
	else
	{
		i = export_quotes4(input, ms, i);
		(*ms)->exp_start = i;
	}
	return (i);
}
