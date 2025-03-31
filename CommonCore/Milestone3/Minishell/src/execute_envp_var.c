#include "../includes/minishell.h"

char	*remove_quotes_expand(char *cmd)
{
	char	*n_cmd;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	n_cmd = malloc(sizeof(char) * (ft_strlen(cmd) + 1));
	while (cmd[i])
	{
		if (cmd[i] == '"')
			i++;
		if (cmd[i] == '$')
			i++;
		if (cmd[i] != '"' && cmd[i] != '$')
			n_cmd[j++] = cmd[i++];
	}
	free(cmd);
	n_cmd[j] = '\0';
	return (n_cmd);
}

char	*get_cmd(char *cmd, int *qt)
{
	size_t	i;
	char	*new_cmd;
	size_t	j;

	while (*cmd == ' ' || *cmd == '$')
		cmd++;
	i = 0;
	j = 0;
	while (cmd[i] && cmd[i] != ' ')
		i++;
	new_cmd = malloc(sizeof(char) * (i + 1));
	while (j < i)
	{
		new_cmd[j] = cmd[j];
		j++;
	}
	new_cmd[j] = '\0';
	if (ft_strchr(new_cmd, '"') != NULL)
	{
		new_cmd = remove_quotes_expand(new_cmd);
		*qt = 1;
	}
	return (new_cmd);
}

void	execute_v2(char *command, char *input2, t_ms **ms)
{
	char	*input;

	input = get_extracmd(command);
	free(input2);
	if (input != NULL)
	{
		choose_builtin(input, ms);
		free(input);
	}
}

void	check_valid_cmd(char **input2, int *check, t_ms **ms)
{
	char	**sp_cmd;
	char	*input;

	input = ft_strjoin("$", *input2);
	input = expand_heredoc(ms, 1, input);
	sp_cmd = ft_split(input, ' ');
	if (sp_cmd[0] && sp_cmd[1] && ft_strchr(sp_cmd[1], '-') != NULL)
	{
		ft_put_error(ERROR_CMD_, "%s", input);
		(*check) = 0;
		free(*input2);
		*input2 = ft_strdup("");
		ft_free(sp_cmd);
		return ;
	}
	ft_free(sp_cmd);
	free(input);
}

void	execute_variable(char *command, t_ms **ms, char **cmdsplit)
{
	size_t	i;
	int		check;
	char	*input2;
	int		qt;

	qt = 0;
	ft_free(cmdsplit);
	input2 = get_cmd(command, &qt);
	i = 0;
	check = 0;
	while ((*ms)->envp[i])
	{
		if (ft_strnstr((*ms)->envp[i], input2, ft_strlen(input2)) != NULL)
		{
			check = 1;
			break ;
		}
		i++;
	}
	if (qt)
		check_valid_cmd(&input2, &check, ms);
	if (check)
		found_var(input2, ms, i, command);
	else
		execute_v2(command, input2, ms);
}
