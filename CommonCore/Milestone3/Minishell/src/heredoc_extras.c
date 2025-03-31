#include "../includes/minishell.h"

char	*get_extra_here2(t_ms **ms)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen((*ms)->h.n_str2)));
	while ((*ms)->h.n_str2[i])
	{
		if ((*ms)->h.n_str2[i] == 'h' && (*ms)->h.n_str2[i + 1])
			if ((*ms)->h.n_str2[i + 1] == 'e' && (*ms)->h.n_str2[i + 2])
				if ((*ms)->h.n_str2[i + 2] == 'r' && (*ms)->h.n_str2[i + 3])
					if ((*ms)->h.n_str2[i + 3] == 'e' && (*ms)->h.n_str2[i + 4])
						if ((*ms)->h.n_str2[i + 4] == 'd')
							break ;
		str[j++] = (*ms)->h.n_str2[i++];
	}
	str[j] = '\0';
	return (str);
}

void	get_extra_heredoc(t_ms **ms, size_t i)
{
	char	*str;
	size_t	j;
	char	*str2;

	j = 0;
	str = malloc(sizeof(char) * (ft_strlen((*ms)->cmd)));
	while ((*ms)->cmd[i])
	{
		str[j++] = (*ms)->cmd[i++];
	}
	str[j] = '\0';
	str2 = ft_strjoin(" ", str);
	free(str);
	if ((*ms)->h.n_str2)
	{
		str = get_extra_here2(ms);
		free((*ms)->h.n_str2);
		(*ms)->h.n_str2 = ft_strjoin(str, str2);
		free(str);
		free(str2);
	}
	else
		(*ms)->h.n_str2 = str2;
}

void	check_extra_heredoc1_1(t_ms **ms, size_t i, size_t j)
{
	char	*str;
	char	*str2;

	if (!(*ms)->h.n_str2)
	{
		(*ms)->h.n_str2 = malloc(sizeof(char) * ft_strlen((*ms)->cmd));
		while ((*ms)->cmd[i])
			(*ms)->h.n_str2[j++] = (*ms)->cmd[i++];
		(*ms)->h.n_str2[j] = '\0';
	}
	else
	{
		str = malloc(sizeof(char) * ft_strlen((*ms)->cmd));
		while ((*ms)->cmd[i])
			str[j++] = (*ms)->cmd[i++];
		str[j] = '\0';
		str2 = ft_strdup((*ms)->h.n_str2);
		free((*ms)->h.n_str2);
		(*ms)->h.n_str2 = ft_strjoin(str2, str);
		free(str);
		free(str2);
	}
}

void	check_extra_heredoc1(t_ms **ms)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((*ms)->cmd[i])
	{
		if ((*ms)->cmd[i] == '<')
		{
			i += 2;
			break ;
		}
		i++;
	}
	while ((*ms)->cmd[i] && (*ms)->cmd[i] == ' ')
		i++;
	while ((*ms)->cmd[i] && (*ms)->cmd[i] != ' ' && (*ms)->cmd[i] != '<' && \
	(*ms)->cmd[i] != '>')
		i++;
	if ((*ms)->cmd[i])
		check_extra_heredoc1_1(ms, i, j);
}

void	check_extra_heredoc(t_ms **ms)
{
	size_t	i;
	int		found;

	i = 0;
	found = 0;
	while ((*ms)->cmd[i])
	{
		if ((*ms)->cmd[i] == '<')
		{
			i += 2;
			break ;
		}
		i++;
	}
	while ((*ms)->cmd[i])
	{
		if ((*ms)->cmd[i] == '<' || (*ms)->cmd[i] == '>')
		{
			found++;
			break ;
		}
		i++;
	}
	if (found)
		get_extra_heredoc(ms, i);
}
