/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:43:22 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:43:22 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*envvar(char *input2, t_ms **ms, size_t i, char *command)
{
	char	*input;

	input = ft_strtrim((*ms)->envp[i], input2);
	free(input2);
	input2 = ft_strtrim(input, "=");
	free(input);
	if (ft_strlen(input2))
		input = get_extracmd1(command, input2);
	else
		input = get_extracmd1(command, input2);
	return (input);
}

char	*get_cmd1(char *cmd)
{
	size_t	i;
	char	*new_cmd;
	size_t	j;

	while (*cmd != '$')
		cmd++;
	cmd++;
	i = 0;
	j = 0;
	while (cmd[i] && cmd[i] != ' ')
		i++;
	new_cmd = malloc(sizeof(char) * (i + 1));
	while (j < i)
	{
		new_cmd[j] = cmd[j];
		j++;
	}
	new_cmd[j] = '\0';
	return (new_cmd);
}

int	get_check(t_ms **ms, char *input2, int check, size_t *i)
{
	while ((*ms)->envp[*i])
	{
		if (ft_strstr_1((*ms)->envp[*i], input2) != NULL && input2[1] != '\0')
		{
			check = 1;
			break ;
		}
		(*i)++;
	}
	return (check);
}

char	*expander(char *command, t_ms **ms)
{
	int		check;
	char	*input2;
	char	*input;
	size_t	i;

	i = 0;
	input2 = get_cmd1(command);
	check = 0;
	check = get_check(ms, input2, check, &i);
	if (check)
		input = envvar(input2, ms, i, command);
	else
	{
		free(input2);
		input2 = NULL;
		input = get_extracmd1(command, input2);
	}
	free(command);
	return (input);
}
