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

void	ft_readcmd(t_ms **ms)
{
	heredoc_rm(ms);
	(*ms)->here_check = 0;
	(*ms)->pipes = NULL;
	get_prompt(ms);
	//(*ms)->input = readline((*ms)->prompt);
	//(*ms)->input = readline("minishell: ");
	(*ms)->input = readline("minishell: ");
	g_signal_handler(ms);
	if ((*ms)->input == NULL)
	{
		(*ms)->is_exit = 1;
		ft_putstr_fd("exit\n", 1);
	}
	else if ((*ms)->input[0] != '\0' && (*ms)->is_exit == 0)
	{
		add_history((*ms)->input);
		handle_input(ms, 1);
	}
	ft_free_gnl(&(*ms)->prompt);
	(*ms)->prompt = NULL;
	g_signal_handler(ms);
}
