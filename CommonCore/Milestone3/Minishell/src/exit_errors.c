/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:43:16 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:43:17 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_too_big(char *num)
{
	if (ft_strlen(num) > 19)
		return (1);
	if (ft_strlen(num) == 19 && ft_strcmp(num, "9223372036854775807") > 0)
		return (1);
	return (0);
}

void	handle_exit_with_no_num_arguments(char *cmd, t_ms **ms)
{
	ft_putstr_fd("exit\n", 1);
	ft_put_error(ERROR_NUM_ARG, "%s", cmd);
	(*ms)->exit_status = 2;
	(*ms)->is_exit = 1;
}

void	handle_exit_valid_arguments(char *cmd, t_ms **ms)
{
	(*ms)->is_exit = 1;
	(*ms)->exit_status = ft_atol(cmd);
	ft_putstr_fd("exit\n", 1);
}

void	handle_exit_with_too_many_arguments(char *cmd, t_ms **ms)
{
	size_t	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] < '0' || cmd[i] > '9' )
		{
			(*ms)->exit_status = 2;
			ft_putstr_fd("exit\n", 1);
			ft_put_error(ERROR_NUM_ARG, "%s", cmd);
			(*ms)->is_exit = 1;
			return ;
		}
		i++;
	}
	ft_putstr_fd("exit\n", 1);
	ft_putstr_fd(ERROR_ARG, 2);
	(*ms)->exit_status = 1;
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
