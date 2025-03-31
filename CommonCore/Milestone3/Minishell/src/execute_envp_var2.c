/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_envp_var2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:42:48 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 11:31:24 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_extracmd(char *cmd)
{
	size_t	i;
	char	*extra_cmd;
	size_t	j;

	i = 0;
	while (*cmd == ' ' || *cmd == '$')
		cmd++;
	while (cmd[i] && cmd[i] != ' ')
		i++;
	while (cmd[i] && cmd[i] == ' ')
		i++;
	if (!cmd[i])
		return (NULL);
	else
	{
		j = i;
		while (cmd[i])
			i++;
		extra_cmd = malloc(sizeof(char) * (i - j + 1));
		i = 0;
		while (cmd[j])
			extra_cmd[i++] = cmd[j++];
		extra_cmd[i] = '\0';
	}
	return (extra_cmd);
}

char	*get_input(char *input, char *input2)
{
	char	*input3;

	input3 = ft_strjoin(input2, " ");
	free(input2);
	input2 = ft_strjoin(input3, input);
	free(input);
	free(input3);
	input = input2;
	return (input);
}

void	found_var(char *input2, t_ms **ms, size_t i, char *command)
{
	char	*input;

	input = trim_str_export2(ms, i);
	free(input2);
	input2 = ft_strtrim(input, "=");
	free(input);
	if (ft_strlen(input2))
	{
		input = get_extracmd(command);
		if (input != NULL)
			input = get_input(input, input2);
		else
		{
			(*ms)->input_expand = ft_strdup(input2);
			free(input2);
		}
	}
	else
		(*ms)->input_expand = get_extracmd(command);
	choose_builtin((*ms)->input_expand, ms);
	if ((*ms)->input_expand)
		free((*ms)->input_expand);
	(*ms)->input_expand = NULL;
}
