/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:43:48 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:43:48 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_export_errors2(char *input, t_ms **ms, size_t check_eq)
{
	size_t	i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '=')
			check_eq = 1;
		else if (input[i] == '-' && !check_eq)
			return (ft_put_error(ERROR_EXP_P, "%s", input), (*ms)->exit_status \
			= 1, 1);
		else if (input[i] != '_' && !ft_isalpha(input[i]) \
		&& !ft_isdigit(input[i]) && input[i] != '+' && !check_eq && \
		input[i] != '\'' && input[i] != '"' && input[i] != '$')
			return (ft_put_error(ERROR_EXP_P, "%s", input), (*ms)->exit_status \
			= 1, 1);
		else if (i > 2)
		{
			if (input[i] == '=' && input[i - 1] == ' ' && input[i + 1] == ' ')
				return (ft_put_error(ERROR_EXP_P, "%s", input), \
				(*ms)->exit_status = 1, 1);
		}
		i++;
	}
	return (0);
}

int	check_export_errors(char *input, t_ms **ms)
{
	size_t	i;
	size_t	check_eq;

	i = 0;
	check_eq = 0;
	while (input[i])
	{
		if (i == 0 && input[i] == '+')
			return (ft_put_error(ERROR_EXP_P, "%s", input), \
			(*ms)->exit_status = 1, 1);
		if (ft_isdigit(input[i]) && i == 0)
			return (ft_put_error(ERROR_EXP_P, "%s", input), (*ms)->exit_status \
			= 1, 1);
		else if (input[i] == '=' && i == 0)
			return (ft_put_error(ERROR_EXP_P, "%s", input), (*ms)->exit_status \
			= 1, 1);
		else if (input[i] == '+' && input[i + 1] != '=')
			return (ft_put_error(ERROR_EXP_P, "%s", input), (*ms)->exit_status \
			= 1, 1);
		else
			if (check_export_errors2(input, ms, check_eq))
				return (1);
		i++;
	}
	return (0);
}

char	*get_new_export(char **n_array)
{
	size_t	h;
	char	*str;
	char	*str2;

	h = 1;
	str = NULL;
	if (n_array && n_array[0] != NULL)
	{
		str = ft_strdup(n_array[0]);
		while (n_array[h])
		{
			str2 = ft_strjoin(str, " ");
			free(str);
			str = ft_strjoin(str2, n_array[h]);
			h++;
			free(str2);
		}
	}
	else
		return (ft_free(n_array), NULL);
	ft_free(n_array);
	str2 = ft_strjoin("export ", str);
	free(str);
	return (str2);
}

void	realoc_export(t_ms **ms, size_t i)
{
	size_t	j;
	char	**n_array;
	char	*str;

	(*ms)->a = 0;
	j = 0;
	while ((*ms)->export[j])
		j++;
	n_array = malloc(sizeof(char *) * j);
	j = 0;
	while ((*ms)->export[j])
	{
		if (j == i)
			j++;
		if ((*ms)->export[j])
			n_array[(*ms)->a++] = ft_strdup((*ms)->export[j++]);
	}
	n_array[(*ms)->a] = 0;
	ft_free((*ms)->export);
	(*ms)->export = NULL;
	str = get_new_export(n_array);
	if (str == NULL)
		return ;
	handle_export(str, ms);
	free(str);
}

int	check_e(t_ms **ms)
{
	size_t	i;

	i = 0;
	while ((*ms)->export[i])
	{
		if (check_export_errors((*ms)->export[i], ms))
		{
			realoc_export(ms, i);
			return (1);
		}
		i++;
	}
	return (0);
}
