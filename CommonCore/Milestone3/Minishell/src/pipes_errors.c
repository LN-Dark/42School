#include "../includes/minishell.h"

int	check_pipe_errors3(t_ms **ms, size_t i)
{
	i++;
	if ((*ms)->input[i] == ' ')
	{
		while ((*ms)->input[i] == ' ')
			i++;
		if ((*ms)->input[i] == '|')
		{
			(*ms)->exit_status = 2;
			return (ft_put_error(ERROR_SNTAX, "%s", "|"), 1);
		}
	}
	return (0);
}

int	check_pipe_errors2(t_ms **ms, int check, size_t i)
{
	while ((*ms)->input[i])
	{
		if (((*ms)->input[i] == '"' || (*ms)->input[i] == '\'') && !check)
		{
			check = 1;
			i++;
		}
		if ((*ms)->input[i] && (*ms)->input[i] == '|' && !check)
			if (check_pipe_errors3(ms, i))
				return (1);
		if ((*ms)->input[i] && ((*ms)->input[i] == '"' || \
		(*ms)->input[i] == '\'') && check)
		{
			check = 0;
			i++;
		}
		if ((*ms)->input[i])
			i++;
	}
	return (0);
}

int	check_pipe_errors(t_ms **ms)
{
	size_t	i;
	int		check;

	i = 0;
	check = 0;
	while ((*ms)->input[i] == ' ')
		i++;
	if ((*ms)->input[i] == '|')
	{
		{
			(*ms)->exit_status = 2;
			return (ft_put_error(ERROR_SNTAX, "%s", "|"), 1);
		}
	}
	if (check_pipe_errors2(ms, check, i))
		return (1);
	return (0);
}

void	set_pipe_vars(t_ms **ms)
{
	(*ms)->k = 0;
	(*ms)->i = 0;
	(*ms)->p = 0;
	(*ms)->nr_commands = 0;
}
