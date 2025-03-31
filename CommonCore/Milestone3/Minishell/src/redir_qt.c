#include "../includes/minishell.h"

void	redirect_quotes_tmp(char *command_trim, int	*check1, int *check2, \
	size_t *i)
{
	if (command_trim[*i] == '\'' && !(*check1))
	{
		(*check1)++;
		(*i)++;
	}
	if (command_trim[*i] && command_trim[*i] == '\'' && *check1)
	{
		(*check1)--;
		(*i)++;
	}
	if (command_trim[*i] && command_trim[*i] == '"' && !(*check2))
	{
		(*check2)++;
		(*i)++;
	}
	if (command_trim[*i] && command_trim[*i] == '"' && *check2)
	{
		(*check2)--;
		(*i)++;
	}
}

int	redirect_quotes(char *command_trim)
{
	size_t	i;
	int		check1;
	int		check2;
	int		found;

	i = 0;
	check1 = 0;
	check2 = 0;
	found = 0;
	while (command_trim[i])
	{
		redirect_quotes_tmp(command_trim, &check1, &check2, &i);
		if (command_trim[i] && (command_trim[i] == '<' \
			|| command_trim[i] == '>') && !check1 && !check2)
		{
			found++;
			i++;
			if (command_trim[i] && (command_trim[i] == '<' \
				|| command_trim[i] == '>'))
				i++;
		}
		if (command_trim[i])
			i++;
	}
	return (found);
}
