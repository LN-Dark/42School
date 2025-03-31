/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:53:49 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:43:41 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void	temp_array(char *input, t_ms **ms)
{
	char	**tmpvar;
	size_t	i;

	if ((*ms)->tmpvar == NULL)
	{
		tmpvar = malloc(sizeof(char *) * 2);
		tmpvar[0] = ft_strdup(input);
		tmpvar[1] = 0;
	}
	else
	{
		i = 0;
		while ((*ms)->tmpvar[i])
			i++;
		tmpvar = malloc(sizeof(char *) * (i + 2));
		while ((*ms)->tmpvar[i])
		{
			tmpvar[i] = (*ms)->tmpvar[i];
			i++;
		}
		tmpvar[i] = ft_strdup(input);
		i++;
		tmpvar[i] = 0;
	}
}
