/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execs2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:42:30 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 19:17:35 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*remove_quotes_execute2(char *str)
{
	char	*str2;

	str2 = ft_strtrim(str, "\n");
	free(str);
	return (str2);
}

char	*remove_quotes_execute1(char *cmd, size_t i, size_t j)
{
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(cmd) + 1));
	while (cmd[i])
	{
		if (cmd[i] == '"')
		{
			i++;
			while (cmd[i])
			{
				if (cmd[i] == '"')
				{
					i++;
					break ;
				}
				str[j++] = cmd[i++];
			}
		}
		while (cmd[i] == '\'')
			i++;
		if (cmd[i] && cmd[i] != '"' )
			str[j++] = cmd[i++];
	}
	str[j] = '\0';
	return (remove_quotes_execute2(str));
}

char	*remove_quotes_execute(char *cmd)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (cmd[i] && cmd[i] == ' ')
		i++;
	if (cmd[i] == '"' || cmd[i] == '\'')
	{
		i++;
		while (cmd[i] && cmd[i] != ' ')
		{
			if (cmd[i] == '\'' || cmd[i] == '"')
				break ;
			i++;
		}
		if (cmd[i] == ' ')
			return (ft_strdup(cmd));
	}
	i = 0;
	return (remove_quotes_execute1(cmd, i, j));
}

char	*remove_quotes_execute_exp(char *cmd, size_t i)
{
	size_t	j;
	char	*str;

	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(cmd + 1)));
	while (cmd[i])
	{
		if (cmd[i] == '\'')
		{
			i++;
			while (cmd[i] && cmd[i] != '\'')
				str[j++] = cmd[i++];
			if (cmd[i] == '\'')
				i++;
		}
		if (cmd[i] && cmd[i] == '"')
		{
			while (cmd[i] && cmd[i] != '"')
				str[j++] = cmd[i++];
			if (cmd[i] == '"')
				i++;
		}
	}
	str[j] = '\0';
	return (str);
}

void	empty_command(char *command, t_ms **ms)
{
	ft_put_error(ERROR_CMD_, "%s", command);
	(*ms)->exit_status = 127;
}
