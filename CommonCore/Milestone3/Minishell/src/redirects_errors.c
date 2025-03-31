#include "../includes/minishell.h"

int	check_redir(char *cmd)
{
	size_t	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '<' && cmd[i + 1] && cmd[i + 1] == '<' && cmd[i + 2] && \
		(cmd[i + 2] == '<' || cmd[i + 2] == '>'))
		{
			ft_put_error(ERROR_SNTAX, "%s", "<");
			return (0);
		}
		if (cmd[i] == '>' && cmd[i + 1] && cmd[i + 1] == '>' && cmd[i + 2] && \
			(cmd[i + 2] == '<' || cmd[i + 2] == '>'))
		{
			ft_put_error(ERROR_SNTAX, "%s", ">");
			return (0);
		}
		if (cmd[i] == '>' && cmd[i + 1] && cmd[i + 1] == '<')
		{
			ft_put_error(ERROR_SNTAX, "%s", "<");
			return (0);
		}
		i++;
	}
	return (1);
}
