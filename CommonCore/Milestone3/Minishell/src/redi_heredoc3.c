/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redi_heredoc3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:36:49 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:42:13 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void	free_controld(t_ms **ms)
{
	if ((*ms)->h.bff)
	{
		free((*ms)->h.bff);
		(*ms)->h.bff = NULL;
	}
	if ((*ms)->h.split_cmd)
	{
		ft_free((*ms)->h.split_cmd);
		(*ms)->h.split_cmd = NULL;
	}
	if ((*ms)->h.split2)
	{
		ft_free((*ms)->h.split2);
		(*ms)->h.split2 = NULL;
	}
	if ((*ms)->h.n_str)
	{
		free((*ms)->h.n_str);
		(*ms)->h.n_str = NULL;
	}
	if ((*ms)->cmd)
	{
		free((*ms)->cmd);
		(*ms)->cmd = NULL;
	}
}

int	control_d_exit(t_ms **ms, char *e_o_f)
{
	(*ms)->exit_status = 0;
	check_extra_heredoc(ms);
	free((*ms)->cmd);
	(*ms)->cmd = NULL;
	if ((*ms)->h.n_str2 != NULL)
	{
		if ((*ms)->h.n_str)
		{
			free ((*ms)->h.n_str);
			(*ms)->h.n_str = NULL;
		}
		control_d(ms, e_o_f);
	}
	else
	{
		ft_put_error(ERROR_HERE, "%s", e_o_f);
		free(e_o_f);
		free_controld(ms);
	}
	return (0);
}

void	control_c_exit(t_ms **ms, char *e_o_f)
{
	if (g_signal == 130)
	{
		free_controld(ms);
		g_signal_handler(ms);
		free(e_o_f);
		free_ms(ms);
	}
}

int	check_command_before(t_ms **ms, char *e_o_f)
{
	char	*str;

	str = ft_strtrim((*ms)->h.split_cmd[0], " ");
	if (ft_strcmp(str, e_o_f) != 0)
	{
		(*ms)->h.n_str2 = ft_strdup((*ms)->h.split_cmd[0]);
		free(str);
		str = ft_strtrim((*ms)->h.n_str2, e_o_f);
		free((*ms)->h.n_str2);
		(*ms)->h.n_str2 = str;
		return (1);
	}
	else
	{
		free(str);
		return (0);
	}
}

char	*remove_word(char *e_o_f)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(e_o_f) + 1));
	while (e_o_f[i] && e_o_f[i] != ' ')
	{
		str[i] = e_o_f[i];
		i++;
	}
	str[i] = '\0';
	free(e_o_f);
	return (str);
}
