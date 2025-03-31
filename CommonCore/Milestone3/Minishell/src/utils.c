/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:53:49 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:43:35 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

char	*ft_remove_special_chars(char *str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	result = (char *)ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!result)
		return (NULL);
	while (str[i])
	{
		if (str[i] != '"' && str[i] != '\'' && str[i] != '\\')
			result[j++] = str[i];
		i++;
	}
	result[j] = '\0';
	return (free(str), result);
}

char	*get_env_var_value(t_ms **ms, char *var)
{
	int	i;
	int	var_len;

	i = 0;
	var_len = ft_strlen(var);
	while ((*ms)->envp[i])
	{
		if (ft_strncmp((*ms)->envp[i], var, var_len) == 0
			&& (*ms)->envp[i][var_len] == '=')
			return (ft_strdup((*ms)->envp[i] + var_len + 1));
		i++;
	}
	return (NULL);
}

int	is_valid_env_var_name(char *name)
{
	int	i;

	i = 1;
	if (!(ft_isalpha(name[0]) || name[0] == '_'))
		return (0);
	while (name[i] != '\0')
	{
		if (!(ft_isalnum(name[i]) || name[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

int	is_special_character(char character)
{
	if (character == '\'' || character == '\"' || character == '\\')
		return (1);
	return (0);
}
