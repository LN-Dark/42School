/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redi_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:53:49 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:41:53 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void	remove_redir2(size_t j, char *command, char **str, size_t i)
{
	int	check;

	check = 0;
	while (command[j])
	{
		if (command[j] == '<' || command[j] == '>' || command[j] == ' ' \
			|| command[j] == '\t')
		{
			check = 1 ;
			break ;
		}
		j++;
	}
	if (check)
	{
		while (command[j] == ' ' || command[j] == '\t')
			j++;
		while (command[j])
			(*str)[i++] = command[j++];
	}
	(*str)[i] = '\0';
}

size_t	get_j_redir(size_t j, char *command, int check1, int check2)
{
	while (command[j] && (command[j] == ' ' || command[j] == '\t'))
		j++;
	check1 = 0;
	check2 = 0;
	if (command[j] && command[j] == '\'')
		check1++;
	if (command[j] && command[j] == '"')
		check2++;
	while (check1 || check2)
	{
		j++;
		if (check1 && command[j] == '\'')
			check1--;
		if (check2 && command[j] == '"')
			check2--;
	}
	return (j);
}

void	remove_redir3(char *command, t_ms **ms, size_t *j, char *str)
{
	char	c;

	c = (*ms)->redi.c;
	while (command[*j])
	{
		if (command[*j] == c && !(*ms)->redi.check1 && !(*ms)->redi.check2)
			break ;
		if (!(*ms)->redi.check1 && command[*j] == '\'')
			(*ms)->redi.check1++;
		if (!(*ms)->redi.check2 && command[*j] == '"')
			(*ms)->redi.check2++;
		str[(*ms)->redi.i++] = command[(*j)++];
		if (command[*j] == c && !(*ms)->redi.check1 && !(*ms)->redi.check2)
			break ;
		if ((*ms)->redi.check1 && command[*j] == '\'')
		{
			(*ms)->redi.check1--;
			str[(*ms)->redi.i++] = command[(*j)++];
		}
		if ((*ms)->redi.check2 && command[*j] == '"')
		{
			(*ms)->redi.check2--;
			str[(*ms)->redi.i++] = command[(*j)++];
		}
	}
}

void	init_vars_redir(size_t i, char c, t_ms **ms, int check1)
{
	(*ms)->redi.check1 = check1;
	(*ms)->redi.check2 = check1;
	(*ms)->redi.i = i;
	(*ms)->redi.c = c;
	(*ms)->x = 0;
	(*ms)->y = 0;
}

char	*remove_redir(char *command, char c, int nb, t_ms **ms)
{
	size_t	i;
	size_t	j;
	int		check1;
	int		check2;

	i = 0;
	j = 0;
	check1 = 0;
	check2 = 0;
	init_vars_redir(i, c, ms, check1);
	if (search_for_quotes(command, c))
		get_without_quotes(command, c, ms);
	else
	{
		(*ms)->str_redir = malloc(sizeof(char) * (ft_strlen(command) + 1));
		remove_redir3(command, ms, &j, (*ms)->str_redir);
		if (nb == 2)
			j += 2;
		else
			j++;
		j = get_j_redir(j, command, check1, check2);
		remove_redir2(j, command, &(*ms)->str_redir, (*ms)->redi.i);
	}
	return ((*ms)->str_redir);
}
