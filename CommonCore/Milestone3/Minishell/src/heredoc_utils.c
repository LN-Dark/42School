/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:53:49 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:40:47 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

int	heredoc_creat_file(t_ms **ms)
{
	if (access("heredoc", F_OK) == 0)
	{
		if (access("heredoc1", F_OK) == 0)
		{
			if (access("heredoc2", F_OK) == 0)
			{
				if (access("heredoc3", F_OK) == 0)
					(*ms)->hdc_nm = "heredoc4";
				else
					(*ms)->hdc_nm = "heredoc3";
			}
			else
				(*ms)->hdc_nm = "heredoc2";
		}
		else
			(*ms)->hdc_nm = "heredoc1";
	}
	else
		(*ms)->hdc_nm = "heredoc";
	return (open((*ms)->hdc_nm, O_CREAT | O_TRUNC | O_WRONLY, 0777));
}

void	heredoc(char *command, t_ms **ms)
{
	pid_t	pid;
	int		status;
	int		i;
	int		j;

	i = 0x7F;
	j = 0xFF;
	status = 0;
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (!pid)
		heredoc_child(command, ms);
	else
		waitpid(pid, &status, 0);
	if (status & j)
		(*ms)->exit_status = status & i;
	else
		(*ms)->exit_status = (status >> 8) & j;
}

void	heredoc_rm(t_ms **ms)
{
	if (access("heredoc", F_OK) == 0)
		choose_builtin("rm -f heredoc", ms);
	if (access("heredoc1", F_OK) == 0)
		choose_builtin("rm -f heredoc1", ms);
	if (access("heredoc2", F_OK) == 0)
		choose_builtin("rm -f heredoc2", ms);
	if (access("heredoc3", F_OK) == 0)
		choose_builtin("rm -f heredoc3", ms);
	if (access("heredoc4", F_OK) == 0)
		choose_builtin("rm -f heredoc4", ms);
}
