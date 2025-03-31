/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_qt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:53:49 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:41:46 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void	redirect_quotes_tmp(char *command_trim, int	*check1, int *check2, \
	size_t *i)
{
	if (command_trim[*i] == '\'' && !(*check1))
	{
		(*check1)++;
		(*i)++;
	}
	if (command_trim[*i] && command_trim[*i] == '\'' && *check1)
	{
		(*check1)--;
		(*i)++;
	}
	if (command_trim[*i] && command_trim[*i] == '"' && !(*check2))
	{
		(*check2)++;
		(*i)++;
	}
	if (command_trim[*i] && command_trim[*i] == '"' && *check2)
	{
		(*check2)--;
		(*i)++;
	}
}

int	redirect_quotes(char *command_trim)
{
	size_t	i;
	int		check1;
	int		check2;
	int		found;

	i = 0;
	check1 = 0;
	check2 = 0;
	found = 0;
	while (command_trim[i])
	{
		redirect_quotes_tmp(command_trim, &check1, &check2, &i);
		if (command_trim[i] && (command_trim[i] == '<' \
			|| command_trim[i] == '>') && !check1 && !check2)
		{
			found++;
			i++;
			if (command_trim[i] && (command_trim[i] == '<' \
				|| command_trim[i] == '>'))
				i++;
		}
		if (command_trim[i])
			i++;
	}
	return (found);
}
