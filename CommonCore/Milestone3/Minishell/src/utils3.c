/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 08:55:45 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:43:28 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void	add_to_empty(char *(*empty)[52])
{
	(*empty)[0] = "PATH=/usr/bin";
	(*empty)[1] = "SHELL=/usr/bin/bash";
	(*empty)[2] = "SESSION_MANAGER=local/c1r10s1.42porto.com:@/tmp/.\
	ICE-unix/6452,unix/c1r10s1.42porto.com:/tmp/.ICE-unix/6452";
	(*empty)[3] = "QT_ACCESSIBILITY=1";
	(*empty)[4] = "COLORTERM=truecolor";
	(*empty)[5] = "XDG_CONFIG_DIRS=/etc/xdg/xdg-ubuntu:/etc/xdg";
	(*empty)[6] = "SSH_AGENT_LAUNCHER=gnome-keyring";
	(*empty)[7] = "XDG_SESSION_PATH=/org/freedesktop/DisplayManager/Session0";
	(*empty)[8] = "XDG_MENU_PREFIX=gnome-";
	(*empty)[9] = "GNOME_DESKTOP_SESSION_ID=this-is-deprecated";
	(*empty)[10] = "GTK_IM_MODULE=ibus";
	(*empty)[11] = "LANGUAGE=en";
	(*empty)[12] = "SSH_AUTH_SOCK=/run/user/102598/keyring/ssh";
	(*empty)[13] = "XMODIFIERS=@im=ibus";
	(*empty)[14] = "DESKTOP_SESSION=ubuntu";
	(*empty)[15] = "FT_HOOK_NAME=login-user";
	(*empty)[16] = "GTK_MODULES=gail:atk-bridge";
	(*empty)[17] = "DBUS_STARTER_BUS_TYPE=session";
	(*empty)[18] = "FT_HOOK_PATHNAME=login-user.d";
	(*empty)[19] = "PWD=/home/hfilipe-/42/PushMiniShell";
	(*empty)[20] = "KRB5CCNAME=FILE:/tmp/krb5cc_102598_NwQQKe";
	(*empty)[21] = "XDG_SESSION_DESKTOP=ubuntu";
	(*empty)[22] = "LOGNAME=hfilipe-";
	(*empty)[23] = "XDG_SESSION_TYPE=x11";
}

void	add_to_empty2(char *(*empty)[52])
{
	(*empty)[24] = "GPG_AGENT_INFO=/run/user/102598/gnupg/S.gpg-agent:0:1";
	(*empty)[25] = "SYSTEMD_EXEC_PID=6452";
	(*empty)[26] = "XAUTHORITY=/home/hfilipe-/.Xauthority";
	(*empty)[27] = "XDG_GREETER_DATA_DIR=/var/lib/lightdm-data/hfilipe-";
	(*empty)[28] = "GDM_LANG=en";
	(*empty)[29] = "HOME=/home/hfilipe-";
	(*empty)[30] = "LANG=en_US.UTF-8";
	(*empty)[31] = "XDG_CURRENT_DESKTOP=ubuntu:GNOME";
	(*empty)[32] = "VTE_VERSION=6800";
	(*empty)[33] = "XDG_SEAT_PATH=/org/freedesktop/DisplayManager/Seat0";
	(*empty)[34] = "GNOME_TERMINAL_SCREEN=/org/gnome/Terminal/screen/1faa\
	0d91_3a88_429b_8be8_410d6ce44f5d";
	(*empty)[35] = "XDG_SESSION_CLASS=user";
	(*empty)[36] = "TERM=xterm-256color";
	(*empty)[37] = "LIBVIRT_DEFAULT_URI=qemu:///system";
	(*empty)[38] = "USER=hfilipe-";
	(*empty)[39] = "GNOME_TERMINAL_SERVICE=:1.395";
	(*empty)[40] = "DISPLAY=:0";
	(*empty)[41] = "SHLVL=2";
	(*empty)[42] = "QT_IM_MODULE=ibus";
	(*empty)[43] = "DBUS_STARTER_ADDRESS=unix:path=/run/user/102598/bus,guid\
	=e30229c252c15d314cd5943667e29eef";
	(*empty)[44] = "XDG_RUNTIME_DIR=/run/user/102598";
	(*empty)[45] = "PS1=\\[\\e[1;44m\\]\\u\\[\\e[0m\\] \\[\\e[1;48;5;21\
	4m\\]\\w\\[\\e[0m\\] \\[\\e[1;41m\\]$(date +%H:%M:%S)\\[\\e[0m\\] \\[\\e\
	[1;42m\\]\\e[1m\\]$(parse_git_branch)\\[\\e[0m\\]\\n\\[\\e[38;5;245m\\]\
	➜ \\[\\e[0m\\]";
}

void	pipe_mini2(t_ms **ms)
{
	static char	path[] = "/usr/bin/firefox";
	char		*cmd;
	char		**cmd1;

	cmd = ft_strdup("firefox https://i.makeagif.com/media/9-16-2016/K\
		a5Dbw.mp4");
	cmd1 = ft_split(cmd, ' ');
	free(cmd);
	execve(path, cmd1, (*ms)->envp);
	ft_free(cmd1);
	free_ms(ms);
}

void	pipe_mini(t_ms **ms)
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
		pipe_mini2(ms);
	else
		waitpid(pid, &status, 0);
	if (status & j)
		(*ms)->exit_status = status & i;
	else
		(*ms)->exit_status = (status >> 8) & j;
}
