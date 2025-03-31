#include "../includes/minishell.h"

char	*get_eof(char *command, t_ms **ms)
{
	char	*e_o_f;

	e_o_f = NULL;
	if (!check_eof_her(command))
		return (NULL);
	command = remove_quotes_heredoc(command, ms);
	(*ms)->h.split_cmd = ft_split(command, '<');
	if ((*ms)->h.split_cmd && (*ms)->h.split_cmd[0] != NULL)
	{
		if ((*ms)->h.split_cmd[1] == NULL)
			e_o_f = ft_strtrim((*ms)->h.split_cmd[0], " ");
		else
		{
			(*ms)->h.split2 = ft_split((*ms)->h.split_cmd[1], ' ');
			if ((*ms)->h.split2[1] == NULL)
				e_o_f = ft_strtrim((*ms)->h.split_cmd[1], " ");
			else
				e_o_f = ft_strtrim((*ms)->h.split2[0], " ");
		}
	}
	free(command);
	if (ft_strchr(e_o_f, ' ') != NULL)
		e_o_f = remove_word(e_o_f);
	e_o_f = remore_redir_eof(e_o_f);
	return (e_o_f);
}

void	heredoc2(t_ms **ms, size_t i, char *e_o_f)
{
	int		output_file;

	if ((*ms)->h.n_str != NULL)
	{
		output_file = heredoc_creat_file(ms);
		ft_putstr_fd((*ms)->h.n_str, output_file);
		close(output_file);
		free((*ms)->h.n_str);
		if ((*ms)->h.split2)
		{
			(*ms)->h.n_str2 = ft_strdup((*ms)->h.split_cmd[0]);
			while ((*ms)->h.split2[i])
			{
				(*ms)->h.bff = ft_strjoin((*ms)->h.n_str2, (*ms)->h.split2[i]);
				free((*ms)->h.n_str2);
				(*ms)->h.n_str2 = ft_strjoin((*ms)->h.bff, " ");
				free((*ms)->h.bff);
				i++;
			}
		}
	}
	else
		if (!check_command_before(ms, e_o_f))
			return (ft_free((*ms)->h.split_cmd));
	heredoc4(ms, e_o_f);
}

void	set_heredocstr(t_ms **ms)
{
	if ((*ms)->h.n_str == NULL)
		(*ms)->h.n_str = ft_strdup((*ms)->h.bff);
	else
	{
		(*ms)->h.n_str2 = ft_strjoin((*ms)->h.n_str, (*ms)->h.bff);
		free((*ms)->h.n_str);
		(*ms)->h.n_str = ft_strdup((*ms)->h.n_str2);
		free((*ms)->h.n_str2);
		(*ms)->h.n_str2 = NULL;
	}
}

int	heredoc3(t_ms **ms, char *e_o_f)
{
	int	read2;

	while (g_signal != 130)
	{
		(*ms)->h.bff = ft_calloc(LINE_MAX + 1, sizeof(char));
		ft_putstr_fd("> ", 0);
		read2 = read(0, (*ms)->h.bff, LINE_MAX);
		if (!read2)
			return (control_d_exit(ms, e_o_f));
		if (read2 < 0)
			control_c_exit(ms, e_o_f);
		(*ms)->h.bff2 = ft_strtrim((*ms)->h.bff, "\n");
		if (compeof(e_o_f, ms) == 0)
			return (free((*ms)->h.bff), free((*ms)->h.bff2), 1);
		if (ft_strchr((*ms)->h.bff, '$') != NULL && !(*ms)->h_found)
			heredoc3_1(ms);
		free((*ms)->h.bff2);
		set_heredocstr(ms);
		free((*ms)->h.bff);
	}
	return (0);
}

void	heredoc_child(char *command, t_ms **ms)
{
	char	*e_o_f;

	e_o_f = NULL;
	(*ms)->h.bff = NULL;
	(*ms)->h.bff2 = NULL;
	(*ms)->h.n_str = NULL;
	(*ms)->h.split2 = NULL;
	(*ms)->h.n_str2 = NULL;
	(*ms)->h.split_cmd = NULL;
	(*ms)->h_found = 0;
	e_o_f = get_eof(command, ms);
	if (!e_o_f)
	{
		ft_putstr_fd(ERROR_ECHO, 2);
		(*ms)->exit_status = 2;
		return ;
	}
	signal(SIGINT, signal_handler_heredoc);
	if (!(heredoc3(ms, e_o_f)))
		return (free_ms(ms));
	heredoc2(ms, 1, e_o_f);
	free(e_o_f);
}
