#include "../includes/minishell.h"

int	handle_pipe_errors_2(t_ms **ms)
{
	if (check_pipe_errors(ms))
		return (1);
	set_pipe_vars(ms);
	return (0);
}

void	control_c_exit_extend(t_ms **ms)
{
	if (g_signal == 130)
		g_signal_handler(ms);
}

void	process_input(t_ms **ms, int n)
{
	if (n == 1)
	{
		(*ms)->input_cont = ft_strndup((*ms)->input, \
			ft_strlen((*ms)->input));
		(*ms)->input_cont = ft_strjoin_gnl((*ms)->input_cont, \
			(*ms)->input_if_needed);
	}
	else if (n == 2)
	{
		(*ms)->input_cont = ft_strndup((*ms)->input, \
			ft_strlen((*ms)->input) - 1);
		(*ms)->input_cont = ft_strjoin_gnl((*ms)->input_cont, \
			(*ms)->input_if_needed);
	}
	ft_free_gnl(&(*ms)->input_if_needed);
}

void	extend_input_if_needed(t_ms **ms, int n)
{
	while (g_signal != 130)
	{
		signal_pipes(ms);
		(*ms)->input_if_needed = readline("> ");
		if ((*ms)->input_if_needed == NULL)
			free_ms(ms);
		else if ((*ms)->input_if_needed[0] == '\0')
		{
			ft_free_gnl(&(*ms)->input_if_needed);
			control_c_exit_extend(ms);
			return (ft_free_gnl(&(*ms)->input_if_needed));
		}
		process_input(ms, n);
		return ;
	}
}

void	split_and_handle_pipes(t_ms **ms)
{
	char	**dividedpipes;
	t_pipe	*new_pipe;

	if (!(*ms)->input_cont)
		dividedpipes = ft_split((*ms)->input_tmp, '|');
	else
		dividedpipes = ft_split((*ms)->input_cont, '|');
	if (!dividedpipes)
	{
		(*ms)->exit_status = 1;
		perror("Error: handling pipes");
		return ;
	}
	new_pipe = ft_calloc(1, sizeof(t_pipe));
	new_pipe->text = ft_strtrim(dividedpipes[0], " ");
	new_pipe->next = NULL;
	(*ms)->pipes = new_pipe;
	handle_input2(dividedpipes, ms, 1);
}
