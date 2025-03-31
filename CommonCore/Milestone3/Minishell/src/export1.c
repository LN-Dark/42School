/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:43:38 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:43:38 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	errors_e_out(char **input_trim, t_ms **ms)
{
	size_t	i;

	i = 0;
	if ((*input_trim)[0] != '\0')
	{
		(*input_trim) = errors_with_quotes((*input_trim), ms);
		if ((*input_trim)[i])
		{
			while ((*input_trim)[i] && (*input_trim)[i] == ' ')
				i++;
			if (!(*input_trim)[i])
			{
				(*ms)->exit_status = 1;
				return (free(*input_trim), 1);
			}
		}
		else
		{
			(*ms)->exit_status = 1;
			return (free(*input_trim), 1);
		}
	}
	return (0);
}
