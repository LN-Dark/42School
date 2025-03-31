#include "../includes/minishell.h"

void	signal_handler_heredoc(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	g_signal = 130;
	close(STDIN_FILENO);
}

void	signal_handler(int sig)
{
	(void)sig;
	if (waitpid(-1, NULL, WNOHANG) == -1)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	g_signal = 130;
}

void	g_signal_handler(t_ms **ms)
{
	if (g_signal == 130)
	{
		(*ms)->exit_status = 130;
		g_signal = 0;
	}
}

void	signal_global(t_ms **ms)
{
	struct sigaction	sa_int;

	sa_int.sa_handler = signal_handler;
	sigemptyset(&sa_int.sa_mask);
	sa_int.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa_int, NULL);
	signal(SIGINT, signal_handler);
	g_signal_handler(ms);
}

void	signal_pipes(t_ms **ms)
{
	struct sigaction	sa_int;

	sa_int.sa_handler = signal_handler_heredoc;
	sigemptyset(&sa_int.sa_mask);
	sa_int.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sa_int, NULL);
	signal(SIGINT, signal_handler_heredoc);
	g_signal_handler(ms);
}
