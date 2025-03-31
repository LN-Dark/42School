#include "../includes/minishell.h"

void	handle_quoted_input(char *new_input, t_ms **ms,
	t_pipe *new_pipe, size_t i)
{
	add_with_quotes(new_input, ms, new_pipe, i);
}

void	handle_input_cont2(t_ms **ms, int type, int i)
{
	if (type == 1)
	{
		if (ft_strchr((*ms)->input_cont, '"') == NULL && \
		ft_strchr((*ms)->input_cont, '\'') == NULL)
			split_and_handle_pipes(ms);
		else
			handle_quoted_input((*ms)->input_cont, ms, NULL, i);
		ft_free_gnl(&(*ms)->input_cont);
	}
	else
	{
		if (ft_strchr((*ms)->input_tmp, '"') == NULL && \
		ft_strchr((*ms)->input_tmp, '\'') == NULL)
			split_and_handle_pipes(ms);
		else
			handle_quoted_input((*ms)->input_tmp, ms, NULL, i);
	}
	signal_global(ms);
}

void	handle_input_cont(t_ms **ms, int type, int i)
{
	if (type == 1)
	{
		if (!(*ms)->input)
			return ;
		if (((*ms)->input[ft_strlen((*ms)->input) - 1] == '|' && \
				(*ms)->input[ft_strlen((*ms)->input) - 2] == '|'))
			extend_input_if_needed(ms, 2);
		else if ((*ms)->input[ft_strlen((*ms)->input) - 1] == '|')
			extend_input_if_needed(ms, 1);
		if (!(*ms)->input_cont)
			(*ms)->input_cont = ft_strdup((*ms)->input);
	}
	handle_input_cont2(ms, type, i);
}

int	handle_input_else(t_ms **ms)
{
	if (ft_strchr((*ms)->input_tmp, '|') != NULL && \
	ft_strstr((*ms)->input_tmp, "<<") != NULL)
		(*ms)->input_tmp = check_here_pipes((*ms)->input_tmp, ms);
	if (!(*ms)->input_tmp)
	{
		if (!(*ms)->last_here_cmd)
			return (1);
		else
			(*ms)->input_tmp = (*ms)->last_here_cmd;
		(*ms)->here_check = 0;
	}
	if (check_and_or((*ms)->input_tmp))
		return (1);
	if (check_mini_pipe((*ms)->input_tmp, ms))
		return (1);
	return (0);
}

void	handle_input(t_ms **ms, int type)
{
	int		i;

	i = 0;
	if (handle_pipe_errors_2(ms))
		return ;
	if (type == 1)
	{
		if (handle_input_if(ms))
			return ;
	}
	else
		if (handle_input_else(ms))
			return ;
	handle_input_cont(ms, type, i);
	if ((*ms)->last_here_cmd)
	{
		(*ms)->nr_commands = 0;
		free((*ms)->input);
		(*ms)->input = NULL;
	}
	else
		rl_replace_line("", 0);
}
