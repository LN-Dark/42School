/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_dot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:40:48 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:40:50 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cd_dotdot3(char **pwd, t_ms **ms, size_t i)
{
	size_t	j;
	char	*str;
	char	*new_pwd;
	char	*new_pwd2;

	j = 0;
	new_pwd = "/";
	new_pwd = ft_strjoin(new_pwd, pwd[j++]);
	while (j < i)
	{
		new_pwd2 = ft_strjoin(new_pwd, "/");
		free(new_pwd);
		new_pwd = ft_strjoin(new_pwd2, pwd[j]);
		free(new_pwd2);
		j++;
	}
	free((*ms)->pwd);
	(*ms)->pwd = new_pwd;
	chdir(new_pwd);
	if (search_pwd(ms, 1))
	{
		str = ft_strjoin("export PWD=", (*ms)->pwd);
		handle_export(str, ms);
		free(str);
	}
}

void	cd_dotdot(t_ms **ms, size_t i)
{
	char	**pwd;
	char	*old_pwd;

	old_pwd = (*ms)->pwd;
	free((*ms)->oldpwd);
	(*ms)->oldpwd = ft_strdup(old_pwd);
	if (search_pwd(ms, 0) || (*ms)->cd == 1)
	{
		old_pwd = ft_strjoin("export OLDPWD=", old_pwd);
		handle_export(old_pwd, ms);
		free(old_pwd);
	}
	pwd = ft_split((*ms)->pwd, '/');
	while (pwd[i + 1])
		i++;
	cd_dotdot3(pwd, ms, i);
	ft_free(pwd);
}

void	cd_dotdot2(t_ms **ms)
{
	char	*old_pwd;

	free((*ms)->oldpwd);
	(*ms)->oldpwd = ft_strdup((*ms)->pwd);
	if (search_pwd(ms, 0) || (*ms)->cd == 1)
	{
		old_pwd = ft_strjoin("export OLDPWD=", (*ms)->oldpwd);
		handle_export(old_pwd, ms);
		free(old_pwd);
	}
	chdir("/");
	if (search_pwd(ms, 1))
	{
		handle_export("export PWD=/", ms);
		free((*ms)->pwd);
	}
	(*ms)->pwd = ft_strdup("/");
}

void	uptdate_oldpwd(t_ms **ms)
{
	char	*old_pwd;

	if (search_pwd(ms, 0) || (*ms)->cd == 1)
	{
		old_pwd = "export OLDPWD=/";
		handle_export(old_pwd, ms);
	}
	free((*ms)->oldpwd);
	(*ms)->oldpwd = ft_strdup("/");
}

void	handle_cd_dot(t_ms **ms)
{
	size_t	i;

	i = 0;
	if (ft_strcmp((*ms)->pwd, "/") == 0 && ft_strcmp((*ms)->oldpwd, "/") != 0)
		uptdate_oldpwd(ms);
	else if (ft_strcmp((*ms)->pwd, "/") == 0 && \
	ft_strcmp((*ms)->oldpwd, "/") == 0)
	{
		(*ms)->exit_status = 0;
		return ;
	}
	else if (ft_strcmp((*ms)->pwd, "/home") == 0)
		cd_dotdot2(ms);
	else
		cd_dotdot(ms, i);
}
