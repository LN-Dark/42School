/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redi_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 08:55:03 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:42:03 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void	fd_error(t_ms**ms, char *str, int nb)
{
	if (nb == 1)
		ft_put_error(ERROR_FORD, "%s", str);
	if (str)
		free(str);
	(*ms)->exit_status = nb;
	free_ms(ms);
}

void	output_child(t_ms **ms, char *cmd_trim, size_t *h)
{
	char		*str;
	struct stat	sfile_stat;
	int			fd;
	char		*cmd_trim2;

	str = get_str_and_check(ms, h, cmd_trim, 1);
	if (str == NULL)
		fd_error(ms, str, 2);
	if (stat(str, &sfile_stat) == 0)
		check_str_output(str, ms);
	fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		fd_error(ms, str, 1);
	free(str);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	remove_redir(cmd_trim, '>', 1, ms);
	cmd_trim2 = ft_strdup((*ms)->str_redir);
	free((*ms)->str_redir);
	(*ms)->str_redir = NULL;
	if (cmd_trim2 && ft_strlen(cmd_trim2) > 0)
		child_call(ms, cmd_trim2);
	else
		free(cmd_trim2);
	free_ms(ms);
}

void	output_redirect(t_ms **ms, char *cmd_trim)
{
	pid_t	pid;
	int		i;
	int		j;
	int		status;
	size_t	h;

	status = 0;
	h = 0;
	j = 0xFF;
	i = 0x7F;
	pid = fork();
	if (pid == 0)
		output_child(ms, cmd_trim, &h);
	else
	{
		waitpid(pid, &status, 0);
		if (status & j)
			(*ms)->exit_status = status & i;
		else
			(*ms)->exit_status = (status >> 8) & j;
	}
}

void	append_child(t_ms **ms, char *cmd_trim, size_t *h)
{
	char		*str;
	struct stat	sfile_stat;
	int			fd;
	char		*cmd_trim2;

	str = get_str_and_check(ms, h, cmd_trim, 2);
	if (str == NULL)
		fd_error(ms, str, 2);
	if (stat(str, &sfile_stat) == 0)
		check_str_output(str, ms);
	fd = open(str, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
		fd_error(ms, str, 1);
	free(str);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	remove_redir(cmd_trim, '>', 2, ms);
	cmd_trim2 = ft_strdup((*ms)->str_redir);
	free((*ms)->str_redir);
	(*ms)->str_redir = NULL;
	if (cmd_trim2 && ft_strlen(cmd_trim2) > 0)
		child_call(ms, cmd_trim2);
	free_ms(ms);
}

void	output_append(t_ms **ms, char *cmd_trim)
{
	pid_t	pid;
	int		i;
	int		j;
	int		status;
	size_t	h;

	status = 0;
	j = 0xFF;
	i = 0x7F;
	h = 0;
	pid = fork();
	if (pid == 0)
		append_child(ms, cmd_trim, &h);
	else
	{
		waitpid(pid, &status, 0);
		if (status & j)
			(*ms)->exit_status = status & i;
		else
			(*ms)->exit_status = (status >> 8) & j;
	}
}
