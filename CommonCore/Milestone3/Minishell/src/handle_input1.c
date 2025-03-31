/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:55:45 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:41:22 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void	handle_input2(char **dividedpipes, t_ms **ms, size_t i)
{
	t_pipe	*curr;
	t_pipe	*new_pipe;

	while (dividedpipes[i])
	{
		new_pipe = ft_calloc(1, sizeof(t_pipe));
		new_pipe->text = ft_strdup(dividedpipes[i]);
		new_pipe->next = NULL;
		curr = (*ms)->pipes;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new_pipe;
		i++;
	}
	ft_free(dividedpipes);
	(*ms)->nr_commands = i;
	process_pipes(ms, i);
	free_pipes(ms);
}

void	pipes_with_quotes(char *cmd, t_ms **ms, size_t check)
{
	check = 0;
	while (cmd[(*ms)->i])
	{
		if (cmd[(*ms)->i] == '|')
		{
			check++;
			break ;
		}
		if (cmd[(*ms)->i] == '\'')
		{
			(*ms)->i++;
			while (cmd[(*ms)->i] && cmd[(*ms)->i] != '\'')
				(*ms)->i++;
			(*ms)->i++;
			break ;
		}
		if (cmd[(*ms)->i] == '"')
		{
			gofowardpipes(ms, cmd);
			break ;
		}
		(*ms)->i++;
	}
	alloc_for_pipe(cmd, ms, check);
}

void	alloc_for_pipe(char *cmd, t_ms **ms, size_t check)
{
	if (!(*ms)->nr_commands)
		node1(ms, check, cmd);
	else
		nextnodes(ms, cmd, check);
	if (!(cmd[(*ms)->i]))
		return (free_pipes(ms));
	pipes_with_quotes(cmd, ms, 0);
}

void	add_with_quotes(char *cmd, t_ms **ms, t_pipe *new_pipe, size_t i)
{
	size_t	check;

	check = 0;
	if (check_unclose_quotes(cmd))
	{
		(*ms)->exit_status = 1;
		return (ft_put_error(ERROR_QT, "%s", cmd));
	}
	if (ft_strchr(cmd, '|') == NULL)
	{
		new_pipe = ft_calloc(1, sizeof(t_pipe));
		new_pipe->text = ft_strdup(cmd);
		new_pipe->next = NULL;
		(*ms)->pipes = new_pipe;
		i = 1;
		(*ms)->nr_commands = 1;
		process_pipes(ms, i);
		free(new_pipe->text);
		free((*ms)->pipes);
		(*ms)->pipes = NULL;
	}
	else
		pipes_with_quotes(cmd, ms, check);
}

int	handle_input_if(t_ms **ms)
{
	if (ft_strchr((*ms)->input, '|') != NULL && \
	ft_strstr((*ms)->input, "<<") != NULL)
		(*ms)->input = check_here_pipes((*ms)->input, ms);
	if (!(*ms)->input)
	{
		if (!(*ms)->last_here_cmd)
			return (1);
		else
			(*ms)->input = (*ms)->last_here_cmd;
		(*ms)->here_check = 0;
	}
	if (check_and_or((*ms)->input))
		return (1);
	if (check_mini_pipe((*ms)->input, ms))
		return (1);
	return (0);
}
