#include "../includes/minishell.h"

char	*check_other_redir(char *str)
{
	size_t	i;
	char	*str2;

	str2 = malloc(sizeof(char) * (ft_strlen(str) + 1));
	i = 0;
	while (str[i])
	{
		str2[i] = str[i];
		i++;
		if (str[i] == '<' || str[i] == '>')
			break ;
	}
	str2[i] = '\0';
	free(str);
	return (str2);
}

int	is_redirect_operator(char *str, int i)
{
	if (str[i] == '>' || str[i] == '<')
	{
		if (str[i + 1] == str[i])
			return (2);
		if (i > 0)
		{
			if ((str[i] == '>' && str[i - 1] == '-') \
			|| (str[i] == '>' && str[i - 1] == '='))
				return (0);
		}
		return (1);
	}
	return (0);
}

int	redirect_no_quotes(t_ms **ms, int redirect_type)
{
	size_t	i;

	i = 0;
	while ((*ms)->cmd)
	{
		redirect_type = is_redirect_operator((*ms)->cmd, i);
		if (redirect_type == 2)
		{
			if ((*ms)->cmd[i] == '<')
				heredoc((*ms)->cmd, ms);
			else
				output_append(ms, (*ms)->cmd);
			break ;
		}
		else if (redirect_type == 1)
		{
			if ((*ms)->cmd[i] == '<')
				input_redirect(ms, (*ms)->cmd);
			else
				output_redirect(ms, (*ms)->cmd);
			break ;
		}
		i++;
	}
	return (redirect_type);
}

int	handle_redi(char *command_trim, t_ms **ms, int redirect_type)
{
	if (!redirect_quotes(command_trim))
		return (0);
	redirect_type = redirect_no_quotes(ms, redirect_type);
	return (redirect_type);
}

void	process_redirects(char *command, t_ms **ms)
{
	int		redirect_type;

	redirect_type = 0;
	if (!check_redir(command))
		return ;
	(*ms)->cmd = ft_strtrim(command, " ");
	redirect_type = handle_redi((*ms)->cmd, ms, redirect_type);
	if (redirect_type == 0)
		choose_builtin((*ms)->cmd, ms);
	if ((*ms)->cmd)
		free((*ms)->cmd);
	(*ms)->cmd = NULL;
}
