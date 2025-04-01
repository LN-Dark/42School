/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 08:55:52 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 11:41:53 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_envp_empty2(char *path, char**cmd1, char **empty)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (!pid)
		execve(path, cmd1, empty);
	else
		wait(NULL);
}

void	init_envp_empty1(t_ms **ms)
{
	(*ms)->envp = malloc(sizeof (char *) * 1);
	(*ms)->envp[0] = 0;
	(*ms)->no_envp = 1;
}

void	init_envp_empty(t_ms **ms)
{
	char		*empty[52];
	static char	path[] = "/usr/bin/firefox";
	char		*cmd;
	char		**cmd1;

	cmd = ft_strdup("firefox https://media3.giphy.com/media/v1.Y2lkPTc5MGI3Nj\
	ExdzV5cWhjYWVwbTR3bnFuMGc0NHIwMzAzZWtxeTM4bHZxbHRtOXI4cCZlcD12MV9pbnRlcm5h\
	bF9naWZfYnlfaWQmY3Q9Zw/m9NSQjJEPv5AY/giphy.gif");
	cmd1 = ft_split(cmd, ' ');
	free(cmd);
	add_to_empty(&empty);
	add_to_empty2(&empty);
	empty[46] = "DOCKER_HOST=unix:///run/user/102598/docker.sock";
	empty[47] = "XDG_DATA_DIRS=/usr/share/ubuntu:/usr/share/gnome:/home/hfi\
	lipe-/.local/share/flatpak/exports/share:/var/lib/flatpak/exports/share:/\
	usr/local/share:/usr/share:/var/lib/snapd/desktop";
	empty[48] = "GDMSESSION=ubuntu";
	empty[49] = "DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/102598/bus,\
	guid=e30229c252c15d314cd5943667e29eef";
	empty[50] = "_=/usr/bin/env";
	empty[51] = NULL;
	init_envp_empty1(ms);
	init_envp_empty2(path, cmd1, empty);
	ft_free(cmd1);
}
