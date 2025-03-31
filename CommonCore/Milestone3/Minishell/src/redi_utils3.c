#include "../includes/minishell.h"

char	*remove_strq(char *str)
{
	size_t	i;
	size_t	j;
	char	*str2;

	i = 0;
	j = 0;
	str2 = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i])
	{
		while (str[i] == '\'' || str[i] == '"')
			i++;
		if (str[i])
			str2[j++] = str[i++];
	}
	str2[j] = '\0';
	free(str);
	return (str2);
}

int	search_for_quotes(char *cmd, char c)
{
	int		found;
	size_t	i;

	i = 0;
	found = 0;
	while (cmd[i] && cmd[i] != c)
	{
		if (cmd[i] == '\'' || cmd[i] == '"')
			found++;
		i++;
	}
	if (found)
		return (0);
	while (cmd[i])
	{
		if (cmd[i] == '\'' || cmd[i] == '"')
			found++;
		i++;
	}
	if (found)
		return (0);
	return (1);
}

void	get_without_quotes(char *cmd, char c, t_ms **ms)
{
	(*ms)->str_e = malloc(sizeof(char) * (ft_strlen(cmd) + 1));
	ft_bzero((*ms)->str_e, ft_strlen(cmd) + 1);
	while (cmd[(*ms)->y] && cmd[(*ms)->y] != c)
		(*ms)->str_e[((*ms)->x)++] = cmd[((*ms)->y)++];
	while (cmd[(*ms)->y] && (cmd[(*ms)->y] == '<' || \
	cmd[(*ms)->y] == '>' || cmd[(*ms)->y] == ' '))
		((*ms)->y)++;
	if ((*ms)->str_e[(*ms)->x] == ' ')
		while ((*ms)->str_e[(*ms)->x] == ' ')
			((*ms)->x)--;
	while (cmd[(*ms)->y] && cmd[(*ms)->y] != '<' && \
	cmd[(*ms)->y] != '>' && cmd[(*ms)->y] != ' ')
		((*ms)->y)++;
	if (cmd[(*ms)->y] == ' ')
		while (cmd[(*ms)->y] == ' ')
			((*ms)->y)++;
	if (!cmd[(*ms)->y])
		(*ms)->str_e[(*ms)->x] = '\0';
	else
	{
		while (cmd[(*ms)->y])
			(*ms)->str_e[((*ms)->x)++] = cmd[((*ms)->y)++];
		(*ms)->str_e[(*ms)->x] = '\0';
	}
	(*ms)->str_redir = (*ms)->str_e;
}

void	child_call(t_ms **ms, char *cmd)
{
	free((*ms)->cmd);
	(*ms)->cmd = NULL;
	process_redirects2(cmd, ms);
}

void	check_str_output(char *str, t_ms **ms)
{
	if (access(str, X_OK) < 0 || access(str, R_OK) < 0)
	{
		ft_put_error(ERROR_PERMS, "%s", str);
		free(str);
		(*ms)->exit_status = 1;
		free_ms(ms);
	}
}
