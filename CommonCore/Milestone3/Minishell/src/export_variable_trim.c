/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_variable_trim.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:45:19 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 11:36:37 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*trim_str_export(t_ms **ms)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = 0;
	str = malloc(sizeof(char) * (ft_strlen((*ms)->envp[(*ms)->p]) + 1));
	i = 0;
	while ((*ms)->envp[(*ms)->p][i] && (*ms)->envp[(*ms)->p][i] != '=')
		i++;
	if ((*ms)->envp[(*ms)->p][i] && (*ms)->envp[(*ms)->p][i] == '=')
	{
		i++;
		while ((*ms)->envp[(*ms)->p][i])
			str[j++] = (*ms)->envp[(*ms)->p][i++];
	}
	str[j] = '\0';
	return (str);
}

char	*trim_str_export2(t_ms **ms, size_t h)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = 0;
	str = malloc(sizeof(char) * (ft_strlen((*ms)->envp[h]) + 1));
	i = 0;
	while ((*ms)->envp[h][i] && (*ms)->envp[h][i] != '=')
		i++;
	if ((*ms)->envp[h][i] && (*ms)->envp[h][i] == '=')
	{
		i++;
		while ((*ms)->envp[h][i])
			str[j++] = (*ms)->envp[h][i++];
	}
	str[j] = '\0';
	return (str);
}
