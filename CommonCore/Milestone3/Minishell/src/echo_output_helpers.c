/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_output_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:42:04 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:42:05 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	skip_initial_spaces(char *input, int *i)
{
	while (input[*i] && input[*i] != ' ')
		(*i)++;
	while (input[*i] && input[*i] == ' ')
		(*i)++;
	if (!input[*i])
		return ;
}

void	skip_leading_control_chars(char *cmd, int *i)
{
	while (cmd[*i] && cmd[*i] < 33)
		(*i)++;
}

char	*ft_get_d_quotes(char *cmd)
{
	int	i;
	int	start;

	i = 0;
	start = 1;
	while ((cmd + start)[i])
	{
		if ((cmd + start)[i] == '"')
			break ;
		i++;
	}
	return (ft_strndup((cmd + start), i));
}

char	*ft_get_s_quotes(char *cmd)
{
	int	i;
	int	start;

	i = 0;
	start = 1;
	while ((cmd + start)[i])
	{
		if ((cmd + start)[i] == '\'')
			break ;
		i++;
	}
	return (ft_strndup((cmd + start), i));
}
