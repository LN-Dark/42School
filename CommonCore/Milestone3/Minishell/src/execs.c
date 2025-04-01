/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:42:24 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 19:17:34 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	choose_builtin3(char *command, t_ms **ms, char **commandsplit)
{
	char	*cmd2;
	size_t	i;

	i = 0;
	cmd2 = ft_strdup(command);
	if (ft_strchr(command, '\'') == NULL)
	{
		command = remove_quotes_execute(command);
		command = expand_heredoc(ms, 1, command);
	}
	else
		command = remove_quotes_execute_exp(command, i);
	if (command == NULL || command[0] == '\0')
	{
		ft_put_error(ERROR_CMD_, "%s", cmd2);
		free(cmd2);
		(*ms)->exit_status = 127;
		return ;
	}
	free(cmd2);
	ft_free(commandsplit);
	commandsplit = NULL;
	execute_pipe(command, ms);
	free(command);
}

int	choose_builtin2(char *command, t_ms **ms, char **commandsplit)
{
	if (ft_strcmp(commandsplit[0], "cd") == 0)
		builtin_cd(command, ms);
	else if (ft_strcmp(commandsplit[0], "export") == 0)
		handle_export(command, ms);
	else if (ft_strcmp(commandsplit[0], "unset") == 0)
		unset(command, ms);
	else if (ft_strcmp(commandsplit[0], "env") == 0)
		print_env(ms, command);
	else if (ft_strcmp(commandsplit[0], "exit") == 0)
		builtin_exit(command, ms);
	else if (commandsplit[0][0] == '$' && commandsplit[0][1] != '\0' \
	&& commandsplit[0][1] != '?')
		return (execute_variable(command, ms, commandsplit), 0);
	else if (ft_strchr(commandsplit[0], '='))
		add_tmp_var(command, ms, commandsplit);
	else if (ft_strcmp(commandsplit[0], "sudo") == 0)
	{
		ft_put_error(ERROR_PERMS, "%s", commandsplit[0]);
		(*ms)->exit_status = 126;
	}
	else
		return (choose_builtin3(command, ms, commandsplit), 0);
	return (1);
}

char	*str_without_special(char *str)
{
	char	*str2;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str2 = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (str[i] && (str[i] == ' ' || (str[i] >= 7 && str[i] >= 9)))
	{
		while (str[i] && str[i] < 33)
		i++;
	}
	while (str[i])
		str2[j++] = str[i++];
	str2[j] = '\0';
	free(str);
	return (str2);
}

char	**init_builtin(t_ms **ms, char *command)
{
	char	**commandsplit;
	char	*str;

	(*ms)->check_inpt = 1;
	if (execs_error(command, ms))
		return (NULL);
	str = remove_quotes_execute(command);
	str = str_without_special(str);
	commandsplit = ft_split(str, ' ');
	free(str);
	return (commandsplit);
}

void	choose_builtin(char *command, t_ms **ms)
{
	char	**commandsplit;

	if (check_tabs_and_spaces(command))
		return ;
	commandsplit = init_builtin(ms, command);
	if (!commandsplit)
		return ;
	if (commandsplit[0])
	{
		if (ft_strcmp(commandsplit[0], "pwd") == 0)
			pwd(ms);
		else if (ft_strcmp(commandsplit[0], "echo") == 0)
		{
			builtin_echo(command, ms);
			(*ms)->exit_status = 0;
		}
		else
			(*ms)->check_inpt = choose_builtin2(command, ms, commandsplit);
	}
	else
		empty_command(command, ms);
	if ((*ms)->check_inpt)
		ft_free(commandsplit);
}
