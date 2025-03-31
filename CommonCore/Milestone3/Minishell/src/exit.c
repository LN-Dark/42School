/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:43:11 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:43:11 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	handle_exit_with_argument(char *cmd, t_ms **ms)
{
	int		valid;

	valid = 1;
	if (!is_valid_number(cmd))
		valid = 0;
	if (is_too_big(cmd) && valid)
		handle_exit_with_no_num_arguments(cmd, ms);
	else if (valid)
		handle_exit_valid_arguments(cmd, ms);
	else
		handle_exit_with_no_num_arguments(cmd, ms);
}

void	print_exit(t_ms **ms)
{
	int		found;
	t_pipe	*curr;
	int		i;

	i = 0;
	found = 0;
	curr = (*ms)->pipes;
	while (curr)
	{
		if (ft_strstr(curr->text, "exit") != NULL)
			found = 1;
		curr = curr->next;
		i++;
	}
	if (!(*ms)->pipes)
		ft_putstr_fd("exit\n", 1);
	else if ((*ms)->pipes && found && i == 1)
		ft_putstr_fd("exit\n", 1);
	else if ((*ms)->pipes && !found)
		ft_putstr_fd("exit\n", 1);
}

void	builtin_exit(char *command, t_ms **ms)
{
	char	**splitted_command;
	int		i;
	int		j;

	i = 0;
	while (command[i] && command[i] != ' ')
		i++;
	if (command[i] == ' ')
		i++;
	splitted_command = ft_split(command + i, ' ');
	splitted_command[0] = ft_remove_special_chars(splitted_command[0]);
	j = ft_arraylen(splitted_command) - 1;
	if (j == 0)
		handle_exit_with_argument(splitted_command[0], ms);
	else if (j > 0)
		handle_exit_with_too_many_arguments(splitted_command[0], ms);
	else
	{
		(*ms)->is_exit = 1;
		(*ms)->exit_status = 0;
		print_exit(ms);
	}
	ft_free(splitted_command);
}
