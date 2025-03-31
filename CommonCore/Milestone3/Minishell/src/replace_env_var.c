/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:53:49 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:43:51 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void	init_replace_env_vars(t_replace_env_vars *vars, char *str)
{
	vars->result = ft_strdup(str);
	vars->dollar_pos = ft_strchr(vars->result, '$');
}

char	*find_next_var(t_replace_env_vars *vars)
{
	vars->var = (char *)ft_calloc(256, sizeof(char));
	vars->end = vars->dollar_pos + 1;
	vars->var_len = 0;
	if (*vars->end == '{')
	{
		vars->end++;
		while (*vars->end && *vars->end != '}'
			&& (ft_isalnum(*vars->end) || *vars->end == '_'))
			vars->var[vars->var_len++] = *vars->end++;
		if (*vars->end == '}')
			vars->end++;
	}
	else
		while (*vars->end && (ft_isalnum(*vars->end) || *vars->end == '_'))
			vars->var[vars->var_len++] = *vars->end++;
	vars->var[vars->var_len] = '\0';
	return (vars->var);
}

void	replace_var_with_value(t_replace_env_vars *vars, t_ms **ms)
{
	vars->value = get_env_var_value(ms, vars->var);
	if (vars->value)
	{
		vars->result_len = ft_strlen(vars->result);
		vars->value_len = ft_strlen(vars->value);
		vars->new_result_len = vars->result_len + \
		vars->value_len - vars->var_len - (*(vars->dollar_pos + 1) == '{');
		vars->new_result = (char *)ft_calloc(vars->new_result_len + 1,
				sizeof(char));
		if (!vars->new_result)
			return (free(vars->result), free(vars->value));
		ft_strncpy(vars->new_result, vars->result,
			vars->dollar_pos - vars->result);
		ft_strcat(vars->new_result, vars->value);
		ft_strcat(vars->new_result, vars->end);
		free(vars->result);
		free(vars->value);
		vars->result = vars->new_result;
	}
	else
		ft_memmove(vars->dollar_pos, vars->end, ft_strlen(vars->end) + 1);
}

char	*replace_env_vars(char *str, t_ms **ms)
{
	t_replace_env_vars	vars;

	init_replace_env_vars(&vars, str);
	while (vars.dollar_pos)
	{
		find_next_var(&vars);
		replace_var_with_value(&vars, ms);
		vars.dollar_pos = ft_strchr(vars.result, '$');
	}
	return (vars.result);
}
