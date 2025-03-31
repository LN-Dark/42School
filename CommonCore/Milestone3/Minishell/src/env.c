/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:42:18 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:42:19 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	search_e(char **envp, size_t i)
{
	size_t	j;

	j = 0;
	while (envp[i][j])
	{
		if (envp[i][j] == '=')
		{
			if (envp[i][j + 1] == '\0')
				return (0);
			else
				return (1);
		}
		j++;
	}
	return (1);
}

int	check_env_args(char *cmd)
{
	size_t	i;

	i = 0;
	while (cmd[i] == ' ')
		i++;
	i += 3;
	while (cmd[i] == ' ')
		i++;
	if (!cmd[i])
		return (0);
	return (1);
}

void	print_env2(char **envp, size_t i)
{
	while (envp[i])
	{
		if (ft_strchr(envp[i], '=') && search_e(envp, i))
			ft_printf("%s\n", envp[i]);
		i++;
	}
}

void	print_env(t_ms **ms, char *cmd)
{
	char	**envp;
	size_t	i;
	char	*cmd2;
	char	*cmd3;

	cmd2 = ft_strtrim(cmd, "env");
	cmd3 = cmd2;
	while (*cmd3 == ' ')
		cmd3++;
	if (check_env_args(cmd))
	{
		ft_put_error(ERROR_ENV, "%s", cmd3);
		(*ms)->exit_status = 127;
		free (cmd2);
		return ;
	}
	i = 0;
	envp = (*ms)->envp;
	print_env2(envp, i);
	free(cmd2);
	(*ms)->exit_status = 0;
}
