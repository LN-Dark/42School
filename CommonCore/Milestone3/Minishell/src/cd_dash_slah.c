/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_dash_slah.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:40:42 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 13:46:43 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cd_no_slash2(t_ms **ms, char *path)
{
	char	*new_pwd;
	char	*old_pwd;

	if (search_pwd(ms, 0) || (*ms)->cd == 1)
	{
		old_pwd = ft_strjoin("export OLDPWD=", (*ms)->pwd);
		handle_export(old_pwd, ms);
		free(old_pwd);
	}
	chdir(path);
	if (search_pwd(ms, 1))
	{
		new_pwd = ft_strjoin("export PWD=", path);
		handle_export(new_pwd, ms);
		free(new_pwd);
	}
	free((*ms)->oldpwd);
	(*ms)->oldpwd = (*ms)->pwd;
	(*ms)->pwd = ft_strdup(path);
	(*ms)->exit_status = 0;
}

void	cd_no_slash(t_ms **ms, char *input)
{
	char	*path;
	char	*new_path;
	DIR		*new_dir;

	path = ft_strjoin((*ms)->pwd, "/");
	new_path = ft_strjoin(path, input);
	free(path);
	path = ft_strtrim(new_path, "\n");
	free(new_path);
	new_dir = opendir(path);
	if (new_dir != NULL)
		cd_no_slash2(ms, path);
	else
	{
		ft_putstr_fd("bash: cd: ", 2);
		ft_putstr_fd(input, 2);
		perror(" ");
		(*ms)->exit_status = 1;
	}
	closedir(new_dir);
	free(path);
}

int	search_pwd(t_ms **ms, int nb)
{
	char	*str;
	size_t	i;

	i = 0;
	if (nb)
		str = "PWD";
	else
		str = "OLDPWD";
	while ((*ms)->envp[i])
	{
		if (ft_strstr_1((*ms)->envp[i], str) != NULL )
			return (1);
		i++;
	}
	return (0);
}

void	cd_dash2(t_ms **ms)
{
	char	*tmp;

	ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
	(*ms)->exit_status = 1;
	if ((*ms)->cd == 1)
	{
		tmp = ft_strdup("export OLDPWD");
		handle_export(tmp, ms);
		free(tmp);
	}
}

void	cd_dash(t_ms **ms)
{
	char	*tmp;

	if (search_pwd(ms, 0))
	{
		tmp = (*ms)->pwd;
		(*ms)->pwd = (*ms)->oldpwd;
		(*ms)->oldpwd = tmp;
		if (search_pwd(ms, 0) || (*ms)->cd == 1)
		{
			tmp = ft_strjoin("export OLDPWD=", (*ms)->oldpwd);
			handle_export(tmp, ms);
			free(tmp);
		}
		chdir((*ms)->pwd);
		cd_dash3(ms);
		if (search_pwd(ms, 1))
		{
			tmp = ft_strjoin("export PWD=", (*ms)->pwd);
			handle_export(tmp, ms);
			free(tmp);
		}
		(*ms)->exit_status = 0;
	}
	else
		cd_dash2(ms);
}
