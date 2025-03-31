/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:43:33 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:43:33 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_export(t_ms **ms)
{
	size_t	i;
	size_t	j;
	int		check;

	i = 0;
	while ((*ms)->envp[i])
	{
		check = 0;
		j = 0;
		ft_putstr_fd("declare -x ", 1);
		while ((*ms)->envp[i][j])
		{
			ft_putchar_fd((*ms)->envp[i][j], 1);
			if (check == 0 && (*ms)->envp[i][j] == '=')
			{
				check = 1;
				ft_putchar_fd('"', 1);
			}
			j++;
		}
		if (check)
			ft_putchar_fd('"', 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}

void	replace_vr_value(char *input, t_ms **ms, size_t i)
{
	size_t	j;
	int		check;

	j = 0;
	check = 0;
	while (input[j])
	{
		if (ft_strchr_(input, j))
		{
			check = 1;
			j++;
			break ;
		}
		j++;
	}
	if (check)
		concat_vr_value(input, ms, j, i);
	else
	{
		input = ft_strtrim(input, "\n");
		free ((*ms)->envp[i]);
		(*ms)->envp[i] = ft_strdup(input);
		free(input);
	}
}

void	export_1arg(char *input, t_ms **ms)
{
	char	**envp;
	size_t	i;
	int		check;

	envp = (*ms)->envp;
	i = 0;
	check = 0;
	if (check_dash_existingv(input, ms))
		return ;
	while (envp[i])
	{
		if (ft_strstr_1(envp[i], input) != NULL)
		{
			check = 1;
			break ;
		}
		i++;
	}
	if (check)
		replace_vr_value(input, ms, i);
	else
		insert_string_order(envp, input, ms);
}

int	handle_export2(char **input, t_ms **ms)
{
	size_t	i;

	i = 0;
	while (input[i])
	{
		if (ft_strchr(input[i], '$') != NULL)
		{
			export_existing_v(input[i], ms);
			return (1);
		}
		else
			export_1arg(input[i], ms);
		i++;
	}
	return (0);
}

void	handle_export(char *input, t_ms **ms)
{
	char	*input_trim;

	input = remove_1st_word(input);
	input_trim = ft_strtrim(input, "\n");
	if (errors_e_out(&input_trim, ms))
		return ;
	if (ft_strchr(input, '\'') != NULL || ft_strchr(input, '"' ) != NULL)
	{
		export_quotes(input_trim, ms);
		return ;
	}
	(*ms)->export = ft_split(input_trim, ' ');
	if (check_e(ms))
		return (free(input_trim));
	else if ((*ms)->export[0] == NULL)
	{
		(*ms)->exit_status = 0;
		return (free_export(input_trim, (*ms)->export), print_export(ms));
	}
	else
		if (handle_export2((*ms)->export, ms))
			return (free(input_trim));
	free_export(input_trim, (*ms)->export);
	(*ms)->exit_status = 0;
}
