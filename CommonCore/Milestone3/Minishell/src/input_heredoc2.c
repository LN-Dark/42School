/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_heredoc2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:43:00 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:44:03 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void	heredoc1_child(char *command, t_ms **ms)
{
	if ((*ms)->last_here_cmd)
	{
		free((*ms)->last_here_cmd);
		(*ms)->last_here_cmd = NULL;
	}
	free((*ms)->str_here);
	process_redirects2(command, ms);
	free_ms(ms);
}

void	heredoc_1(char *command, t_ms **ms)
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
		heredoc1_child(command, ms);
	else
		waitpid(pid, &status, 0);
	if (status & j)
		(*ms)->exit_status = status & i;
	else
		(*ms)->exit_status = (status >> 8) & j;
}

void	execute_first_here(t_ms **ms, char *input)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * ft_strlen(input));
	while (input[i] != '|')
	{
		str[i] = input[i];
		i++;
	}
	str[i] = '\0';
	heredoc_1(str, ms);
	free(str);
}
