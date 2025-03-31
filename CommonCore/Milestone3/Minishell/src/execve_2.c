#include "../includes/minishell.h"

void	exit_from_execve(t_ms **ms, char **cmd, char *av, int nb)
{
	if (nb == 1)
	{
		(*ms)->exit_status = 127;
		ft_put_error(ERROR_FORD, "%s", av);
	}
	if (nb == 2)
	{
		ft_put_error(ERROR_CMD_, "%s", av);
		(*ms)->exit_status = 127;
	}
	ft_free(cmd);
	if ((*ms)->input_expand)
	{
		free((*ms)->input_expand);
		(*ms)->input_expand = NULL;
	}
	free(av);
	free_ms(ms);
}

void	change_exit_if_quit(t_ms **ms)
{
	if ((*ms)->exit_status == 3)
		(*ms)->exit_status = 131;
}
