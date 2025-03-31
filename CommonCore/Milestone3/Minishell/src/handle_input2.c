/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:53:49 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:41:19 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

int	check_and_or2(char *input, size_t i)
{
	i += 2;
	while (input[i] == ' ')
		i++;
	if (input[i])
	{
		ft_putstr_fd("This project does not handle bonus\n", 2);
		free(input);
		return (1);
	}
	free(input);
	return (0);
}

int	check_and_or(char *input1)
{
	size_t	i;
	int		found;
	char	*input;

	found = 0;
	i = 0;
	input = ft_strtrim(input1, "\n");
	while (input[i])
	{
		if (input[i] == '\'' && !found)
			found = 1;
		if (input[i] == '"' && !found)
			found = 2;
		if (!found)
			if ((input[i] == '|' && input[i + 1] && input[i + 1] == '|') || \
			(input[i] == '&' && input[i + 1] && input[i + 1] == '&'))
				return (check_and_or2(input, i));
		i++;
		if (input[i] == '\'' && found == 1)
			found = 0;
		if (input[i] == '"' && found == 2)
			found = 0;
	}
	free(input);
	return (0);
}

void	node1(t_ms **ms, size_t check, char *cmd)
{
	char	*str;
	char	*str2;
	t_pipe	*new;

	str = get_str1(ms, cmd);
	if (check || cmd[(*ms)->i] == '\0')
	{
		if (cmd[(*ms)->i] != '\0')
			(*ms)->i++;
		(*ms)->k++;
		str2 = get_str2(ms, str);
		new = malloc(sizeof(t_pipe) * 1);
		new->text = str2;
		new->next = NULL;
		(*ms)->pipes = new;
		(*ms)->nr_commands++;
		if (!cmd[(*ms)->i])
			(process_pipes(ms, (*ms)->nr_commands));
	}
	else
		handltmp(ms, str);
}

void	nextnodes(t_ms **ms, char *cmd, size_t check)
{
	t_pipe	*new;
	char	*str2;
	char	*str;

	str = get_str1(ms, cmd);
	if (check || cmd[(*ms)->i] == '\0')
	{
		if (cmd[(*ms)->i] != '\0')
			(*ms)->i++;
		(*ms)->k++;
		str2 = get_str2(ms, str);
		new = malloc(sizeof(t_pipe) * 1);
		new->text = str2;
		new->next = NULL;
		set_curr(ms, new);
		(*ms)->nr_commands++;
		if (!cmd[(*ms)->i])
			return (process_pipes(ms, (*ms)->nr_commands));
	}
	else
		handltmp(ms, str);
}
