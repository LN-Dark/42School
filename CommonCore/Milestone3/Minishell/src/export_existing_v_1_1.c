/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_existing_v_1_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:44:24 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:44:25 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	get_i_(char *input, size_t i, size_t *j)
{
	size_t	h;

	while (input[i])
	{
		if (input[i] == '=')
		{
			h = i + 1;
			while (input[h] != '$')
			{
				h++;
				(*j)++;
			}
			break ;
		}
		i++;
	}
	return (i);
}

char	*get_concat_in(char *input)
{
	size_t	i;
	size_t	j;
	char	*input2;

	i = 0;
	j = 1;
	i = get_i_(input, i, &j);
	i++;
	input2 = malloc(sizeof(char) * j);
	j = 0;
	while (input[i] != '$')
		input2[j++] = input[i++];
	input2[j] = '\0';
	return (input2);
}

size_t	get_i_ex(t_ms **ms, int *check, char *ex_var_name)
{
	size_t	i;

	i = 0;
	if (*ex_var_name == '$')
		ex_var_name++;
	while ((*ms)->envp[i])
	{
		if (ft_strstr_1((*ms)->envp[i], ex_var_name) != NULL)
		{
			(*check)++;
			break ;
		}
		i++;
	}
	return (i);
}
