/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redi_out_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:36:49 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:42:06 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

int	file_no_name(char *cmd)
{
	while (*cmd)
	{
		if (*cmd == '>' || *cmd == '<')
		{
			cmd++;
			if (!*cmd)
				return (ft_putstr_fd(ERROR_ECHO, 2), 1);
			if (*cmd == '>')
				cmd++;
			if (!*cmd)
				return (ft_putstr_fd(ERROR_ECHO, 2), 1);
			while (*cmd && *cmd == ' ')
				cmd++;
			if (!*cmd)
				return (ft_putstr_fd(ERROR_ECHO, 2), 1);
		}
		if (*cmd)
			cmd++;
	}
	return (0);
}

char	*get_str_end_dot2(char *cmd)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	while (cmd[i] != '<' && cmd[i] != '>')
		i++;
	i++;
	if (cmd[i] == '>')
		i++;
	str = malloc(sizeof(char) * (ft_strlen(cmd) + 1));
	while (cmd[i])
		str[j++] = cmd[i++];
	str[j] = '\0';
	free(cmd);
	return (str);
}

char	*remove_dot(char *str2)
{
	char	*str;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(str2) + 1));
	while (str2[i] && str2[i] != '.')
		str[j++] = str2[i++];
	str[j] = '\0';
	free(str2);
	return (str);
}

char	*get_str_redi_out(char *cmd, t_ms **ms, char *str2, size_t *h)
{
	char	*str;
	char	*str3;

	if (ft_strchr(cmd, '$') && (ft_strchr(cmd, '\'') != NULL || \
	ft_strchr(cmd, '"') != NULL))
	{
		(*ms)->not_expand = 1;
		str = redi_get_str_quotes(str2, h, ms);
		if ((*ms)->not_expand)
			str = expand_heredoc(ms, 1, str);
		free(str2);
	}
	else if (ft_strchr(str2, '$') && (ft_strchr(str2, '\'') == NULL || \
	ft_strchr(str2, '"') == NULL))
	{
		if (ft_strchr(str2, '.') != NULL)
			str3 = remove_dot(str2);
		else
			str3 = str2;
		str = expand_heredoc(ms, 1, str3);
	}
	else
		str = str2;
	return (str);
}

char	*add_end(char *str, char *cmd)
{
	size_t	i;
	char	*str2;
	char	*str3;
	size_t	j;

	i = 0;
	j = 0;
	str2 = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(cmd) + 1));
	while (cmd[i] && cmd[i] != '$')
		i++;
	while (cmd[i] && cmd[i] != ' ' && cmd[i] != '\'' && cmd[i] != '"' \
	&& cmd[i] != '.')
		i++;
	if ((cmd[i] && (cmd[i] == '\'' || cmd[i] == '"')))
		i++;
	if (cmd[i])
	{
		while (cmd[i])
			str2[j++] = cmd[i++];
		str2[j] = '\0';
		str3 = ft_strjoin(str, str2);
		return (free(str), free(str2), str3);
	}
	free(str2);
	return (str);
}
