/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input_heredoc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:53:49 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:41:10 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void	get_newstr(char *str, size_t i, t_ms **ms)
{
	size_t	j;

	i += 2;
	j = 0;
	(*ms)->str_here = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i] && str[i] != '|')
		i--;
	if (str[i] == '|')
		i++;
	while (str[i])
		(*ms)->str_here[j++] = str[i++];
	(*ms)->str_here[j] = '\0';
}

void	get_last_command(char *input, t_ms **ms)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (input[i])
		i++;
	(*ms)->last_here_cmd = malloc(sizeof(char) * (ft_strlen(input) + 1));
	i--;
	while (input[i] != '|')
		i--;
	i++;
	while (input[i])
		(*ms)->last_here_cmd[j++] = input[i++];
	(*ms)->last_here_cmd[j] = '\0';
}

char	*check_here_pipes2(t_ms **ms, char *input, size_t i)
{
	if ((*ms)->here_check == 0)
		get_last_command(input, ms);
	(*ms)->here_check++;
	get_newstr(input, i, ms);
	execute_first_here(ms, input);
	free((*ms)->input);
	(*ms)->input = (*ms)->last_here_cmd;
	if (ft_strchr((*ms)->str_here, '|') != NULL && \
	ft_strstr((*ms)->str_here, "<<") != NULL)
	{
		check_here_pipes((*ms)->str_here, ms);
		free((*ms)->str_here);
		(*ms)->str_here = NULL;
		return (NULL);
	}
	free((*ms)->str_here);
	return (NULL);
}

char	*check_here_pipes1(char *input, t_ms **ms, size_t i)
{
	int		found;
	int		found2;

	found = 0;
	found2 = 0;
	(*ms)->str_here = NULL;
	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' && !found2)
			found2 = 1;
		if (input[i] == '"' && !found2)
			found2 = 2;
		if (input[i] == '|' && !found)
			found++;
		if (input[i] == '<' && input[i + 1] && input[i + 1] == '<' && found \
		&& !found2)
			return (check_here_pipes2(ms, input, i));
		i++;
		if (input[i] == '\'' && found2 == 1)
			found2 = 0;
		if (input[i] == '"' && found2)
			found2 = 2;
	}
	return (input);
}

char	*check_here_pipes(char *input, t_ms **ms)
{
	size_t	i;

	i = 0;
	return (check_here_pipes1(input, ms, i));
}
