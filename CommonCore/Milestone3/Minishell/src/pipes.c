/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:33:47 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:42:43 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void	process_pipes2(t_ms **ms, size_t nr_commands)
{
	t_pipe	*curr;
	pid_t	pid;
	size_t	j;

	allocate_pipes(&(*ms)->fd_pipes, nr_commands, ms);
	curr = (*ms)->pipes;
	j = 0;
	while (j < nr_commands)
	{
		pid = fork();
		if (pid == -1)
			show_pipes_error((*ms)->fd_pipes, 2 * (nr_commands - 1), ms);
		if (pid == 0)
			execute_child(curr, (*ms)->fd_pipes, j, ms);
		if (curr && curr->next)
			curr = curr->next;
		j++;
	}
	close_pipes((*ms)->fd_pipes, 2 * (nr_commands - 1));
	wait_for_children(pid, nr_commands, ms);
	if ((*ms)->fd_pipes)
	{
		free((*ms)->fd_pipes);
		(*ms)->fd_pipes = NULL;
	}
}

void	show_pipes_error(int *fd, size_t count, t_ms **ms)
{
	perror("fork failed");
	close_pipes(fd, count);
	free(fd);
	(*ms)->exit_status = 1;
}

void	process_pipes(t_ms **ms, size_t nr_cmds)
{
	if (!has_unquoted_semicolon_or_asterisk((*ms)->pipes->text))
	{
		if (nr_cmds == 1 && !command_has_args_or_flags((*ms)->pipes->text))
			process_redirects((*ms)->pipes->text, ms);
		else if (nr_cmds > 1 &&!i_string_enclosed((*ms)->pipes->text))
			process_pipes2(ms, nr_cmds);
		else if (command_has_args_or_flags((*ms)->pipes->text))
			process_redirects((*ms)->pipes->text, ms);
		else
		{
			(*ms)->exit_status = 127;
			ft_putstr_fd(ERROR_CMD, 2);
		}
	}
	else
	{
		ft_put_error(ERROR_NRBS, "%s", "; and *");
		(*ms)->exit_status = 0;
	}
}

int	command_has_args_or_flags(char *cmd)
{
	char	*start;
	char	*end;
	char	*ptr;

	if (!i_string_enclosed(cmd))
		return (0);
	start = cmd + 1;
	end = ft_strrchr(cmd, cmd[0]);
	if (!end || end == start)
		return (0);
	ptr = start;
	while (ptr < end)
	{
		if (ft_isspace(*ptr))
			return (1);
		if (*ptr == '-')
			return (1);
		ptr++;
	}
	return (0);
}
