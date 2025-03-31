/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_existing_v1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:44:14 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:44:15 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_slash2(char *str, size_t j)
{
	size_t	i;
	char	*n_str;

	i = 0;
	n_str = malloc(sizeof(char) * (ft_strlen(str) + 2));
	while (str[i])
	{
		if (str[i] == '=')
		{
			n_str[j++] = str[i++];
			n_str[j++] = '\\';
		}
		if (str[i])
			n_str[j++] = str[i++];
	}
	n_str[j] = '\0';
	free(str);
	return (n_str);
}

char	*get_slash(char *str)
{
	size_t	i;
	size_t	j;
	int		check;

	check = 0;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '=')
		{
			i++;
			if (str[i] && str[i] == '$')
			{
				check++;
				break ;
			}
		}
		i++;
	}
	if (check)
		str = get_slash2(str, j);
	return (str);
}

void	free_exv(char *str, char *str2, char *str3)
{
	free(str);
	free(str2);
	free(str3);
}

void	export_existing_v3(char *var_name, char *str, t_ms **ms,
						char *ex_var_name)
{
	size_t	i;
	size_t	j;
	char	*n_str;

	free(ex_var_name);
	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	j = i;
	while (str[j])
		j++;
	n_str = malloc(sizeof(char) * (1 + ft_strlen(var_name)) + (j - i));
	j = 0;
	(*ms)->x = 0;
	while (var_name[(*ms)->x])
		n_str[j++] = var_name[((*ms)->x)++];
	while (str[i])
		n_str[j++] = str[i++];
	n_str[j] = '\0';
	n_str = get_slash(n_str);
	ft_free((*ms)->export);
	(*ms)->export = NULL;
	ex_var_name = ft_strjoin("export ", n_str);
	handle_export(ex_var_name, ms);
	return (free(n_str), free(ex_var_name));
}

int	check_export_variable(char *str, char *str2)
{
	size_t	i;

	i = 0;
	if (*str == '$')
		str++;
	if (!str || !str2 || str[0] == '\0' || str2[0] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] == str2[i])
			i++;
		else
			return (1);
	}
	return (0);
}
