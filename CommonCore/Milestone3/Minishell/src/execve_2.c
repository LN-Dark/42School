/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:42:59 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 16:20:51 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	exit_from_execve(t_ms **ms, char **cmd, char *av, int nb)
{
	if (nb == 1)
	{
		(*ms)->exit_status = 127;
		ft_put_error(ERROR_FORD, "%s", av);
	}
	if (nb == 2)
	{
		ft_put_error(ERROR_CMD_, "%s", av);
		(*ms)->exit_status = 127;
	}
	ft_free(cmd);
	if ((*ms)->input_expand)
	{
		free((*ms)->input_expand);
		(*ms)->input_expand = NULL;
	}
	free(av);
	free_ms(ms);
}

void	change_exit_if_quit(t_ms **ms)
{
	if ((*ms)->exit_status == 3)
		(*ms)->exit_status = 131;
}

int	check_tabs_and_spaces(char *av)
{
	size_t	i;
	i = 0;

	while (av[i] == ' ' || (av[i] >= 7 && av[i] <= 13))
		i++;
	if (!av[i])
		return (1);
	return (0);
}

int	check_has_path(t_ms **ms)
{
	size_t	i;

	i = 0;
	while ((*ms)->envp[i])
	{
		if (ft_strnstr((*ms)->envp[i], "PATH", 4) != NULL)
			return (1);
		i++;
	}
	return (0);
}
