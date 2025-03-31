/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_ex_v.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:41:02 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:41:03 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	builtin_cd2(char *input, t_ms **ms)
{
	if (ft_strcmp(input, "..") == 0)
		handle_cd_dot(ms);
	else if (ft_strcmp(input, ".") == 0)
		(*ms)->exit_status = 0;
	else if (ft_strcmp(input, "~") == 0 || ft_strcmp(input, "") == 0)
		cd_home(ms, input);
	else if (ft_strcmp(input, "-") == 0)
		cd_dash(ms);
	else if (ft_strchr(input, '$') != NULL)
		cd_ex_v(input, ms);
	else if (ft_strchr(input, '/') == NULL)
		cd_no_slash(ms, input);
	else if (ft_strchr(input, '/') != NULL)
		cd_slash(input, ms);
}

void	cd_ex_v2(char *input, t_ms **ms, size_t i)
{
	char	*str;

	str = ft_strtrim((*ms)->envp[i], input);
	input = ft_strtrim_free(str, "=");
	builtin_cd2(input, ms);
	free(input);
	(*ms)->exit_status = 0;
}

void	cd_ex_v(char *input, t_ms **ms)
{
	size_t	i;
	size_t	check;
	char	*input2;

	input2 = input;
	input++;
	i = 0;
	check = 0;
	while ((*ms)->envp[i])
	{
		i++;
		if ((*ms)->envp[i] && ft_strstr_1((*ms)->envp[i], input) != NULL)
		{
			check++;
			break ;
		}
	}
	if (check)
		cd_ex_v2(input2, ms, i);
	else
		cd_home(ms, input);
}
