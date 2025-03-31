/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:41:46 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:41:48 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_double_quotes(char *input, int *i, t_ms **ms)
{
	char	*cmd_execute;

	cmd_execute = ft_get_d_quotes(input + *i);
	if (ft_strlen(cmd_execute) > 0)
	{
		echo_output_direct(cmd_execute, ms, 1);
		*i += ft_strlen(cmd_execute);
		if (ft_strlen(cmd_execute) > 1)
			(*i)++;
	}
	else if (input[*i + 1] && input[*i + 1] != '"')
		ft_printf("%c", input[*i]);
	ft_free_gnl(&cmd_execute);
}

void	handle_single_quotes(char *input, int *i, t_ms **ms, int type)
{
	char	*cmd_execute;

	cmd_execute = ft_get_s_quotes(input + *i);
	if (ft_strlen(cmd_execute) > 0 && count_quotes(input + *i + 1, '\'') > 0)
	{
		if (type == 1)
		{
			ft_printf("'");
			echo_output_direct(cmd_execute, ms, 1);
			ft_printf("'");
			(*i)++;
		}
		else
		{
			ft_printf("%s", cmd_execute);
			(*i)++;
		}
		*i += ft_strlen(cmd_execute);
	}
	else if ((input[*i + 1] && input[*i + 1] != '\'') || type == 1)
		ft_printf("%c", input[*i]);
	else if (input[*i + 1] == '\'')
		(*i)++;
	ft_free_gnl(&cmd_execute);
}

void	handle_tilde(char *input, int i, t_ms **ms)
{
	if ((i == 0 && (input[i + 1] == '\0' || ft_isspace(input[i + 1]))) || \
		(ft_isspace(input[i - 1]) && (input[i + 1] == '\0' \
			|| ft_isspace(input[i + 1]))))
		ft_printf("%s", (*ms)->home);
}

void	echo_output_direct(char *input, t_ms **ms, int type)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '"')
			handle_double_quotes(input, &i, ms);
		else if (input[i] == '\'')
			handle_single_quotes(input, &i, ms, type);
		else if (input[i] == '$' && (input[i + 1] != '\'' && \
			input[i + 1] != '"') && (!ft_isdigit(input[i + 1]) || \
			input[i + 1] == '0') && input[i + 1] > 33)
			handle_dollar_sign(input + i, ms, &i);
		else if (input[i] == '~')
			handle_tilde(input, i, ms);
		else if (!(input[i] == '$' && is_special_character(input[i + 1])) \
			&& !is_special_character(input[i]))
			ft_printf("%c", input[i]);
		i++;
	}
}

void	builtin_echo(char input[LINE_MAX], t_ms **ms)
{
	int		display_newline;
	char	*cmd;
	int		i;

	i = 0;
	if (input)
	{
		skip_initial_spaces(input, &i);
		display_newline = check_display_newline(input, &i);
		cmd = ft_strdup(input + i);
		i = 0;
		skip_leading_control_chars(cmd, &i);
		echo_output_direct(cmd + i, ms, 0);
		ft_free_gnl(&cmd);
		if (display_newline)
			ft_printf("\n");
	}
}
