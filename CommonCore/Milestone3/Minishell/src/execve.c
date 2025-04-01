/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:42:54 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 19:17:36 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_path(char **envp)
{
	size_t	i;
	size_t	check;

	i = 0;
	check = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
	{
		i++;
		if (envp[i] && ft_strnstr(envp[i], "PATH=", 5) != 0)
			check++;
	}
	return (check);
}

void	not_path(t_ms **ms, char **cmd, char *av)
{
	struct stat	sfile_stat;

	if (!check_path((*ms)->envp))
	{
		ft_put_error(ERROR_FORD, "%s", av);
		ft_free(cmd);
		free(av);
		(*ms)->exit_status = 127;
		free_ms(ms);
	}
	else if (ft_strchr(av, '/') != NULL)
	{
		if (stat(av, &sfile_stat) < 0)
			exit_from_execve(ms, cmd, av, 1);
	}
	else
	{
		if (stat(av, &sfile_stat) < 0)
			exit_from_execve(ms, cmd, av, 2);
	}
}

void	check_ex_per(char *cmd, t_ms **ms, char**cmd2, char *av)
{
	if (access(cmd, F_OK == 0))
	{
		if (access(cmd, X_OK) != 0)
		{
			ft_put_error(ERROR_PERMS, "%s", cmd);
			ft_free(cmd2);
			free(av);
			(*ms)->exit_status = 126;
			free_ms(ms);
		}
	}
}

void	execute(char *av, t_ms **ms)
{
	char	**cmd;
	char	*path;

	if (check_tabs_and_spaces(av))
		return (free_ms(ms));
	signal(SIGQUIT, signal_handler_sigquit);
	cmd = ft_split(av, ' ');
	if (access(cmd[0], F_OK | X_OK) == 0 && !check_has_path(ms))
		path = cmd[0];
	else
	{
		path = get_path(cmd[0], (*ms)->envp);
		if (!path)
			not_path(ms, cmd, av);
	}
	if (execve(path, cmd, (*ms)->envp) == -1)
	{
		ft_put_error(ERROR_CMD_, "%s", av);
		ft_free(cmd);
		(*ms)->exit_status = 127;
		free_ms(ms);
	}
}

void	execute_pipe(char *command, t_ms **ms)
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
		execute(command, ms);
	else
		waitpid(pid, &status, 0);
	if (status & j)
		(*ms)->exit_status = status & i;
	else
		(*ms)->exit_status = (status >> 8) & j;
	change_exit_if_quit (ms);
}
