/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:45:10 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:45:10 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*remove_p_sign(char *envp)
{
	size_t	i;
	size_t	j;
	char	*new_envp;

	i = 0;
	while (envp[i])
		i++;
	new_envp = ft_calloc(i, sizeof(char));
	j = 0;
	i = 0;
	while (envp[i])
	{
		if (envp[i] == '+')
			i++;
		new_envp[j++] = envp[i++];
	}
	new_envp[j] = '\0';
	return (free(envp), new_envp);
}

void	get_i_j(size_t *i, size_t *j, char **arr, char *input)
{
	while (arr[*i])
	{
		if (ft_strcmp_(arr[*i], input) > 0)
			break ;
		(*i)++;
	}
	while (arr[*j])
		(*j)++;
}

char	*search_tmpvar(t_ms **ms, char *input)
{
	size_t	h;
	size_t	check;

	check = 0;
	h = 0;
	if (*input == '$')
		input++;
	while ((*ms)->tmpvar[h])
	{
		if (ft_strstr_1((*ms)->tmpvar[h], input) != NULL)
		{
			input = ft_strdup((*ms)->tmpvar[h]);
			check++;
			break ;
		}
		h++;
	}
	if (check)
		realoc_tmp(input, ms);
	else
		input = NULL;
	return (input);
}

size_t	add_to_new_envp(char **arr, size_t j, size_t i, char ***new_envp)
{
	while (j < i)
	{
		(*new_envp)[j] = ft_strdup(arr[j]);
		j++;
	}
	return (j);
}

void	insert_string_order(char **arr, char *input, t_ms **ms)
{
	size_t	i;
	size_t	j;
	char	**new_envp;

	i = 0;
	j = 0;
	get_i_j(&i, &j, arr, input);
	new_envp = ft_calloc((j + 2), sizeof(char *));
	j = 0;
	j = add_to_new_envp(arr, j, i, &new_envp);
	new_envp[j] = ft_strdup(input);
	if (ft_strchr(new_envp[j], '+'))
		new_envp[j] = remove_p_sign(new_envp[j]);
	j++;
	while (arr[i])
		new_envp[j++] = ft_strdup(arr[i++]);
	new_envp[j] = 0;
	free_envp(ms);
	(*ms)->envp = new_envp;
}
