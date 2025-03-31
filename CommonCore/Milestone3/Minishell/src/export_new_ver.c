/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_new_ver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:44:34 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:44:34 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	search_var_env(t_ms **ms, char *input)
{
	size_t	i;

	i = 0;
	while ((*ms)->envp[i])
	{
		if (ft_strstr_1((*ms)->envp[i], input) != NULL )
			return (1);
		i++;
	}
	return (0);
}

int	check_dash_existingv(char *input, t_ms **ms)
{
	size_t	i;

	i = 0;
	while (input[i] && input[i] != '=')
		i++;
	if (input[i] == '=')
		return (0);
	else
	{
		if (input[0] == '_')
		{
			if (input[1])
				return (0);
			else
				return (1);
		}
		else
		{
			if (search_var_env(ms, input))
				return (1);
		}
	}
	return (0);
}
