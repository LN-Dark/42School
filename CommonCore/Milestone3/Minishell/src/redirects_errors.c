/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:53:49 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:43:54 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

int	check_redir(char *cmd)
{
	size_t	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '<' && cmd[i + 1] && cmd[i + 1] == '<' && cmd[i + 2] && \
		(cmd[i + 2] == '<' || cmd[i + 2] == '>'))
		{
			ft_put_error(ERROR_SNTAX, "%s", "<");
			return (0);
		}
		if (cmd[i] == '>' && cmd[i + 1] && cmd[i + 1] == '>' && cmd[i + 2] && \
			(cmd[i + 2] == '<' || cmd[i + 2] == '>'))
		{
			ft_put_error(ERROR_SNTAX, "%s", ">");
			return (0);
		}
		if (cmd[i] == '>' && cmd[i + 1] && cmd[i + 1] == '<')
		{
			ft_put_error(ERROR_SNTAX, "%s", "<");
			return (0);
		}
		i++;
	}
	return (1);
}
