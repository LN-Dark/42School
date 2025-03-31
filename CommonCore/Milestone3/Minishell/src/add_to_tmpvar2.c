/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_tmpvar2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:40:23 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:40:24 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	realoc_tmp(char *input, t_ms **ms)
{
	size_t	i;
	size_t	j;
	char	**str;
	char	**n_str;

	str = (*ms)->tmpvar;
	i = 0;
	j = 0;
	while (str[i])
		i++;
	n_str = malloc(sizeof(char *) * i);
	i = 0;
	while (str[i])
	{
		if (ft_strstr_1(str[i], input) != NULL)
			i++;
		if (str[i])
		{
			n_str[j++] = ft_strdup(str[i]);
			i++;
		}
	}
	n_str[j] = 0;
	ft_free((*ms)->tmpvar);
	(*ms)->tmpvar = n_str;
}

void	addtmp(char *input, t_ms **ms)
{
	size_t	i;
	char	**str;
	char	**n_str;	

	str = (*ms)->tmpvar;
	i = 0;
	while (str[i])
		i++;
	n_str = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (str[i])
	{
		n_str[i] = ft_strdup(str[i]);
		i++;
	}
	n_str[i++] = ft_strdup(input);
	n_str[i] = 0;
	ft_free((*ms)->tmpvar);
	(*ms)->tmpvar = n_str;
}

void	add_tmp_var(char *input, t_ms **ms, char **cmd)
{
	if (cmd[1] != NULL)
	{
		ft_putstr_fd("The program does not handle multiple \
			temporary variables\n", 2);
		return ;
	}
	if (ft_strchr(input, '{') && ft_strchr(input, '}'))
	{
		ft_putstr_fd("The program does not handle temporary arrays\n", 2);
		return ;
	}
	else
		add_tmp_var1(input, ms);
}
