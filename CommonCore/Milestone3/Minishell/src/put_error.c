/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:53:49 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:42:30 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

int	count_occurrences(t_replace_vars *vars)
{
	char	*ins;
	char	*tmp;
	int		count;

	ins = vars->str;
	count = 0;
	tmp = ft_strstr(ins, vars->needle);
	while (tmp)
	{
		count++;
		ins = tmp + vars->len_needle;
		tmp = ft_strstr(ins, vars->needle);
	}
	return (count);
}

char	*allocate_result(t_replace_vars *vars)
{
	vars->len_replace = ft_strlen(vars->replace);
	return ((char *)ft_calloc(ft_strlen(vars->str) + \
		(vars->len_replace - vars->len_needle) * \
		vars->count + 1, sizeof(char)));
}

void	replace_loop(t_replace_vars *vars)
{
	char	*ins;

	while (vars->count--)
	{
		ins = ft_strstr(vars->str, vars->needle);
		vars->len_front = ins - vars->str;
		vars->tmp = ft_strncpy(vars->tmp, vars->str,
				vars->len_front) + vars->len_front;
		vars->tmp = ft_strcpy(vars->tmp, vars->replace) + vars->len_replace;
		vars->str += vars->len_front + vars->len_needle;
	}
}

char	*count_and_allocate_result(t_replace_vars *vars)
{
	char	*ins;
	char	*tmp;

	vars->len_needle = ft_strlen(vars->needle);
	vars->len_replace = ft_strlen(vars->replace);
	ins = vars->str;
	vars->count = 0;
	tmp = ft_strstr(ins, vars->needle);
	while (tmp)
	{
		vars->count++;
		ins = tmp + vars->len_needle;
		tmp = ft_strstr(ins, vars->needle);
	}
	return ((char *)ft_calloc(ft_strlen(vars->str) + (vars->len_replace - \
		vars->len_needle) * vars->count + 1, sizeof(char)));
}

char	*ft_replace_word(char *str, char *needle, char *replace)
{
	t_replace_vars	vars;

	vars.str = str;
	vars.needle = needle;
	vars.replace = replace;
	if (!vars.str || !vars.needle)
		return (NULL);
	if (ft_strlen(vars.needle) == 0)
		return (NULL);
	vars.result = count_and_allocate_result(&vars);
	if (!vars.result)
		return (NULL);
	vars.tmp = vars.result;
	replace_loop(&vars);
	ft_strcpy(vars.tmp, vars.str);
	return (vars.result);
}
