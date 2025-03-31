/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redi_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:53:49 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:41:57 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void	get_j_i(char *command, size_t *i, size_t *j, t_ms **ms)
{
	(*j) = 0;
	while (command[*j])
		(*j)++;
	while (command[*i])
	{
		if (!(*ms)->redi.check1 && command[*i] == '\'')
			(*ms)->redi.check1++;
		if (!(*ms)->redi.check2 && command[*i] == '"')
			(*ms)->redi.check2++;
		if (command[*i] == (*ms)->redi.c && !(*ms)->redi.check1 \
		&& !(*ms)->redi.check2)
			break ;
		(*i)++;
		if ((*ms)->redi.check1 && command[*i] == '\'')
		{
			(*ms)->redi.check1--;
			(*i)++;
		}
		if ((*ms)->redi.check2 && command[*i] == '"')
		{
			(*ms)->redi.check2--;
			(*i)++;
		}
	}
}

int	get_i_redir(t_ms **ms, char *command, size_t *i)
{
	if ((*ms)->redi.check1 && (*ms)->redi.check2)
	{
		while (command[*i] && (command[*i] == ' ' || \
		command[*i] == '\t' || command[*i] == '\n'))
			(*i)++;
	}
	else if (!(*ms)->redi.check1 && !(*ms)->redi.check2)
	{
		if (command[*i] && (command[*i] == ' ' || \
		command[*i] == '\t' || command[*i] == '\n'))
			return (0);
	}
	return (1);
}

void	get_str2_str(char *command, size_t *i, char *str, t_ms **ms)
{
	while (command[*i])
	{
		if (!(*ms)->redi.check1 && command[*i] == '\'')
			(*ms)->redi.check1++;
		if (!(*ms)->redi.check2 && command[*i] == '"')
			(*ms)->redi.check2++;
		if (!(get_i_redir(ms, command, i)))
			break ;
		if (command[*i])
			str[(*ms)->redi.i++] = command[(*i)++];
		if (command[*i] && (*ms)->redi.check1 && command[*i] == '\'')
		{
			(*ms)->redi.check1--;
			str[(*ms)->redi.i++] = command[(*i)++];
		}
		if (command[*i] && (*ms)->redi.check2 && command[*i] == '"')
		{
			(*ms)->redi.check2--;
			str[(*ms)->redi.i++] = command[(*i)++];
		}
	}
	str[(*ms)->redi.i] = '\0';
}

char	*get_str2_2(char *str)
{
	char	*str2;

	if (ft_strchr(str, '\'') != NULL || ft_strchr(str, '"') != NULL )
		str2 = remove_strq(str);
	else
		str2 = str;
	return (str2);
}

char	*get_str(char *command, char c, int nb, t_ms **ms)
{
	size_t	i;
	char	*str;
	size_t	j;
	char	*str2;

	j = 0;
	i = 0;
	(*ms)->redi.check1 = 0;
	(*ms)->redi.check1 = 0;
	(*ms)->redi.c = c;
	get_j_i(command, &i, &j, ms);
	if (nb == 2)
		i++;
	i++;
	str = malloc(sizeof(char) * (j - i + 10));
	(*ms)->redi.check1 = 0;
	(*ms)->redi.check1 = 0;
	(*ms)->redi.i = 0;
	while (command[i] == ' ' || command[i] == '\t')
		i++;
	get_str2_str(command, &i, str, ms);
	str2 = get_str2_2(str);
	return (str2);
}
