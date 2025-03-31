/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_concat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:43:43 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:43:44 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strchr_(char *input, size_t j)
{
	if (input[j] == '=' && input[j - 1] == '+' )
		return (1);
	return (0);
}

size_t	get_j(char *input)
{
	size_t	j;

	j = 0;
	while (input[j])
	{
		if (ft_strchr_(input, j))
		{
			j++;
			break ;
		}
		j++;
	}
	return (j);
}

void	concat_without_eq(t_ms **ms, size_t size, char *input, size_t x)
{
	char	*new_value;
	size_t	i;
	size_t	j;

	j = get_j(input);
	new_value = ft_calloc(size + 2, sizeof(char));
	i = 0;
	while ((*ms)->envp[x][i])
	{
		new_value[i] = (*ms)->envp[x][i];
		i++;
	}
	new_value[i] = '=';
	i++;
	while (input[j])
		new_value[i++] = input[j++];
	new_value[i] = '\0';
	free((*ms)->envp[x]);
	(*ms)->envp[x] = new_value;
}

void	concat_with_eq(t_ms **ms, size_t size, char *input, size_t x)
{
	char	*new_value;
	size_t	i;
	size_t	j;

	j = get_j(input);
	new_value = ft_calloc((size + 1), sizeof(char));
	i = 0;
	while ((*ms)->envp[x][i])
	{
		new_value[i] = (*ms)->envp[x][i];
		i++;
	}
	while (input[j])
		new_value[i++] = input[j++];
	new_value[i] = '\0';
	free((*ms)->envp[x]);
	(*ms)->envp[x] = new_value;
}

void	concat_vr_value(char *input, t_ms **ms, size_t j, size_t x)
{
	size_t	i;
	size_t	size;
	size_t	check;

	i = 0;
	check = 0;
	while (input[i])
		i++;
	size = i - j;
	i = 0;
	while ((*ms)->envp[x][i])
	{
		if ((*ms)->envp[x][i] == '=')
			check = 1;
		i++;
	}
	size += i;
	if (check)
		concat_with_eq(ms, size, input, x);
	else
		concat_without_eq(ms, size, input, x);
}
