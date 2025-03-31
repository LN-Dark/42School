/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 08:55:03 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:42:33 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void	allocate_pipes(int **fd, size_t nr_commands, t_ms **ms)
{
	size_t	j;

	*fd = (int *)ft_calloc((nr_commands - 1) * 2, sizeof(int));
	if (!(*fd))
	{
		perror("calloc failed");
		(*ms)->exit_status = 1;
		free_ms(ms);
	}
	j = -1;
	while (++j < nr_commands - 1)
	{
		if (pipe((*fd) + j * 2) < 0)
		{
			perror("pipe failed");
			close_pipes(*fd, 2 * (nr_commands - 1));
			free(*fd);
			(*ms)->exit_status = 1;
			free_ms(ms);
		}
	}
}

void	close_pipes(int *fd, size_t count)
{
	size_t	i;

	i = -1;
	while (++i < count)
		close(fd[i]);
}

void	setup_child_pipes(int *fd, size_t j, size_t nr_commands, t_ms **ms)
{
	if (j > 0 && dup2(fd[(j - 1) * 2], STDIN_FILENO) == -1)
	{
		perror("dup2 stdin failed");
		(*ms)->exit_status = 1;
		close_pipes(fd, 2 * (nr_commands - 1));
		free(fd);
		free_ms(ms);
	}
	if (j < nr_commands - 1 && dup2(fd[j * 2 + 1], STDOUT_FILENO) == -1)
	{
		perror("dup2 stdout failed");
		(*ms)->exit_status = 1;
		close_pipes(fd, 2 * (nr_commands - 1));
		free(fd);
		free_ms(ms);
	}
	close_pipes(fd, 2 * (nr_commands - 1));
}

void	execute_child(t_pipe *curr, int *fd, size_t j, t_ms **ms)
{
	setup_child_pipes(fd, j, (*ms)->nr_commands, ms);
	process_redirects(curr->text, ms);
	free_ms(ms);
}

void	wait_for_children(pid_t pid, size_t nr_commands, t_ms **ms)
{
	int		status;
	size_t	i;
	int		h;
	int		u;

	h = 0x7F;
	u = 0xFF;
	i = -1;
	status = 0;
	while (++i < nr_commands)
	{
		signal(SIGINT, SIG_IGN);
		waitpid(pid, &status, 0);
		if (pid == -1)
		{
			perror("waitpid failed");
			(*ms)->exit_status = 1;
			free_ms(ms);
		}
		if (status & u)
			(*ms)->exit_status = status & h;
		else
			(*ms)->exit_status = (status >> 8) & u;
		wait(NULL);
	}
}
