/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redi_heredoc2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:53:49 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 17:30:27 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_exit_heredoc(t_ms **ms, char *e_o_f)
{
	if ((*ms)->h.bff)
	{
		free((*ms)->h.bff);
		(*ms)->h.bff = NULL;
	}
	if ((*ms)->h.bff2)
	{
		free((*ms)->h.bff2);
		(*ms)->h.bff2 = NULL;
	}
	if (e_o_f)
		free(e_o_f);
	e_o_f = NULL;
	if ((*ms)->h.split2)
	{
		ft_free((*ms)->h.split2);
		(*ms)->h.split2 = NULL;
	}
	if ((*ms)->h.split_cmd)
	{
		ft_free((*ms)->h.split_cmd);
		(*ms)->h.split_cmd = NULL;
	}
}

int	check_eof_her(char *cmd)
{
	size_t	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '<')
		{
			i++;
			break ;
		}
		i++;
	}
	if (cmd[i] == '<')
		i++;
	while (cmd[i] == ' ' || cmd[i] == '\t')
		i++;
	if (!ft_isalnum(cmd[i]) && cmd[i] != '$' && cmd[i] != '\'' && cmd[i] != '"')
		return (0);
	return (1);
}

void	heredoc4(t_ms **ms, char *e_o_f)
{
	if ((*ms)->h.split2 != NULL)
		ft_free((*ms)->h.split2);
	if ((*ms)->h.split_cmd != NULL)
		ft_free((*ms)->h.split_cmd);
	check_extra_heredoc1(ms);
	if ((*ms)->cmd)
	{
		free((*ms)->cmd);
		(*ms)->cmd = NULL;
	}
	if (e_o_f)
		free(e_o_f);
	e_o_f = NULL;
	if ((*ms)->h.n_str2 != NULL)
		heredoc4_1(ms);
	free_ms(ms);
}

void	heredoc3_1(t_ms **ms)
{
	char	*str;

	(*ms)->h.bff = expand_heredoc(ms, 1, (*ms)->h.bff);
	str = ft_strjoin((*ms)->h.bff, "\n");
	free((*ms)->h.bff);
	(*ms)->h.bff = str;
}

int	compeof(char *e_o_f, t_ms **ms)
{
	char	*str;

	str = ft_strtrim((*ms)->h.bff2, "\n");
	free((*ms)->h.bff2);
	(*ms)->h.bff2 = str;
	return (ft_strcmp((*ms)->h.bff2, e_o_f));
}
