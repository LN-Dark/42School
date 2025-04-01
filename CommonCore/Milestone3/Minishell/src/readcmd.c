#include "../includes/minishell.h"

void	get_prompt(t_ms **ms)
{
	char	*input;
	char	*input2;

	if (!(*ms)->no_envp)
		input = getenv("USER");
	else
		input = " ";
	input2 = ft_strjoin(BG_BLUE BOLD"", input);
	input = ft_strjoin(input2, "   ");
	free(input2);
	input2 = ft_strjoin(input, RESET BG_BLUE"");
	free(input);
	input = ft_strjoin(input2, (*ms)->pwd);
	free(input2);
	(*ms)->prompt = ft_strjoin(input, RESET"\n-> ");
	free(input);
}

void	skip_initial_spaces_radcmd(t_ms **ms)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	if (!(*ms)->input)
		return ;
	while ((*ms)->input[i] && ((*ms)->input[i] == 32 \
		|| ((*ms)->input[i] >= 9 && (*ms)->input[i] <= 13)))
		i++;
	str = ft_strdup((*ms)->input + i);
	ft_free_gnl(&(*ms)->input);
	skip_initial_spaces_radcmd_help(&str, &tmp);
	(*ms)->input = ft_strdup_free(str);
}

void	ft_readcmd(t_ms **ms)
{
	heredoc_rm(ms);
	(*ms)->here_check = 0;
	(*ms)->pipes = NULL;
	get_prompt(ms);
	(*ms)->input = readline((*ms)->prompt);
	g_signal_handler(ms);
	if ((*ms)->input == NULL)
	{
		(*ms)->is_exit = 1;
		ft_putstr_fd("exit\n", 1);
	}
	else if ((*ms)->input[0] != '\0' && (*ms)->is_exit == 0)
	{
		add_history((*ms)->input);
		skip_initial_spaces_radcmd(ms);
		handle_input(ms, 1);
	}
	ft_free_gnl(&(*ms)->prompt);
	(*ms)->prompt = NULL;
	g_signal_handler(ms);
}
