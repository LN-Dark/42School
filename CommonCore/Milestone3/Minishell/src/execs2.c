#include "../includes/minishell.h"

char	*remove_quotes_execute2(char *str)
{
	char	*str2;

	str2 = ft_strtrim(str, "\n");
	free(str);
	return (str2);
}

char	*remove_quotes_execute1(char *cmd, size_t i, size_t j)
{
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(cmd) + 1));
	while (cmd[i])
	{
		if (cmd[i] == '"')
		{
			i++;
			while (cmd[i])
			{
				if (cmd[i] == '"')
				{
					i++;
					break ;
				}
				str[j++] = cmd[i++];
			}
		}
		while (cmd[i] == '\'')
			i++;
		if (cmd[i] && cmd[i] != '"' )
			str[j++] = cmd[i++];
	}
	str[j] = '\0';
	return (remove_quotes_execute2(str));
}

char	*remove_quotes_execute(char *cmd)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (cmd[i] && cmd[i] == ' ')
		i++;
	if (cmd[i] == '"' || cmd[i] == '\'')
	{
		i++;
		while (cmd[i] && cmd[i] != ' ')
		{
			if (cmd[i] == '\'' || cmd[i] == '"')
				break ;
			i++;
		}
		if (cmd[i] == ' ')
			return (ft_strdup(cmd));
	}
	i = 0;
	return (remove_quotes_execute1(cmd, i, j));
}
