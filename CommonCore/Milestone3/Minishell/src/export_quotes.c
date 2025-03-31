/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:44:40 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:44:41 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	export_quotes4(char *input, t_ms **ms, size_t i)
{
	char	*input2;

	if (ft_strchr(input, '\'') != NULL || ft_strchr(input, '"') != NULL)
	{
		input2 = export_quotes5(input, &i, ms);
		add_to_array(ms, i, input2, 0);
		free(input2);
		return (i);
	}
	while (input[i] && input[i] != ' ')
		i++;
	add_to_array(ms, i, input, 0);
	return (i);
}

size_t	get_i(char *input, size_t i)
{
	while (i > 0 && input[i] && input[i] != ' ')
	{
		i--;
	}
	return (i);
}

void	export_quotes2(char *input, t_ms **ms)
{
	size_t	i;

	i = 0;
	(*ms)->exp_start = i;
	while (input[i])
	{
		if (input[i] == '=' || input[i] == '\'' || input[i] == '"')
			i = export_quotes3(input, ms, i);
		i = args_no_equal(i, input, ms);
		if (input[i])
		{
			if (input[i] == ' ')
			{
				while (input[i] == ' ')
					i++;
			}
			else
				i++;
		}
	}
}

void	handle_export3(char **input2, t_ms **ms)
{
	if (input2 == NULL)
		return ;
	(*ms)->export = input2;
	if (check_e(ms))
		return ;
	else if (input2[0] == NULL)
	{
		(*ms)->exit_status = 0;
		return ((ft_free(input2)), print_export(ms));
	}
	else
		handle_export2(input2, ms);
	ft_free(input2);
	(*ms)->exit_status = 0;
}

void	export_quotes(char *input, t_ms **ms)
{
	export_quotes2(input, ms);
	(*ms)->export_in = NULL;
	free(input);
}
