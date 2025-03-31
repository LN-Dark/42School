/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:53:49 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:40:29 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

char	*remove_before_eq(char *str)
{
	while (*str && *str != '=')
		str++;
	if (*str)
		str++;
	return (str);
}

void	init_home(t_ms **ms)
{
	size_t	i;
	int		check;

	i = 0;
	check = 0;
	while ((*ms)->envp[i] && ft_strstr_("HOME", (*ms)->envp[i]) == NULL)
	{
		i++;
		if ((*ms)->envp[i] && ft_strstr_("HOME", (*ms)->envp[i]) != NULL)
			check = 1;
	}
	if (check)
		(*ms)->home = ft_strdup(remove_before_eq((*ms)->envp[i]));
	else
	{
		(*ms)->home = ft_calloc(1, sizeof(char));
		(*ms)->home[0] = '\0';
	}
}

void	init_oldpwd(t_ms **ms)
{
	size_t	i;
	char	*new_odlpwd;
	int		check;

	check = 0;
	i = 0;
	while ((*ms)->envp[i])
	{
		if (ft_strstr_1((*ms)->envp[i], "OLDPWD") != NULL)
		{
			check = 1;
			break ;
		}
		i++;
	}
	if (check)
	{
		new_odlpwd = ft_strdup(remove_before_eq((*ms)->envp[i]));
		(*ms)->oldpwd = new_odlpwd;
	}
	else
	{
		(*ms)->oldpwd = ft_calloc(1, sizeof(char));
		(*ms)->oldpwd[0] = '\0';
	}
}
