/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:53:49 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:41:07 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void	handltmp(t_ms **ms, char *str)
{
	char	*str2;

	if ((*ms)->tmppipe != NULL)
	{
		str2 = ft_strjoin((*ms)->tmppipe, str);
		free(str);
		free((*ms)->tmppipe);
		(*ms)->tmppipe = str2;
	}
	else
		(*ms)->tmppipe = str;
}

char	*get_str2(t_ms **ms, char *str)
{
	char	*str2;

	if ((*ms)->tmppipe != NULL)
	{
		str2 = ft_strjoin((*ms)->tmppipe, str);
		free(str);
		free((*ms)->tmppipe);
		(*ms)->tmppipe = NULL;
	}
	else
		str2 = str;
	return (str2);
}

char	*get_str1(t_ms **ms, char *cmd)
{
	size_t	l;
	char	*str;
	size_t	i;
	size_t	k;

	k = (*ms)->k;
	i = (*ms)->i;
	l = 0;
	str = malloc(sizeof(char) * (i + 1 - k));
	while ((*ms)->k < (*ms)->i)
		str[l++] = cmd[(*ms)->k++];
	str[l] = '\0';
	return (str);
}

void	set_curr(t_ms **ms, t_pipe *new)
{
	t_pipe	*curr;

	curr = (*ms)->pipes;
	if (curr)
	{
		if (curr->next)
		{
			while (curr->next != NULL)
				curr = curr->next;
		}
	}
	curr->next = new;
}

int	check_unclose_quotes(char *cmd)
{
	size_t	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'')
		{
			i++;
			while (cmd[i] && cmd[i] != '\'')
				i++;
			if (cmd[i] != '\'')
				return (1);
		}
		if (cmd[i] == '"')
		{
			i++;
			while (cmd[i] && cmd[i] != '"')
				i++;
			if (cmd[i] != '"')
				return (1);
		}
		i++;
	}
	return (0);
}
