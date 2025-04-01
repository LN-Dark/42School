/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_handle_dollar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:41:53 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 13:10:29 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_dollar_sign_special_cases(char cmd, t_ms **ms)
{
	if (cmd == '?')
		ft_printf("%d", (*ms)->exit_status);
	else if (cmd == '0')
		ft_printf("minishell");
}

void	handle_dollar_sign(char *cmd, t_ms **ms, int *i)
{
	char	*cmd_execute;

	cmd_execute = ft_strndup(cmd + 1, ft_strlen_dolar(cmd + 1));
	if (cmd[1] && (cmd[1] == '?' || cmd[1] == '$' || cmd[1] == '0'))
	{
		handle_dollar_sign_special_cases(cmd[1], ms);
		(*i)++;
	}
	else if (cmd_execute && is_valid_env_var_name(cmd_execute))
	{
		handle_env_var_echo(cmd_execute, ms);
		(*i) += ft_strlen(cmd_execute);
	}
	else if (cmd[0] == '$' && ((!cmd_execute)))
		ft_printf("$");
	else if (!is_valid_env_var_name(cmd_execute))
		ft_printf("$");
	ft_free_gnl(&cmd_execute);
}

int	handle_env_var_echo(char *cmd, t_ms **ms)
{
	char	*env_var;

	env_var = get_env_var_value(ms, cmd);
	if (env_var)
	{
		if (env_var[0] == '\\')
			ft_putstr_fd(env_var + 1, STDOUT_FILENO);
		else
			ft_putstr_fd(env_var, STDOUT_FILENO);
		return (free(env_var), 1);
	}
	return (0);
}
