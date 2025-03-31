#include "../includes/minishell.h"

int	pwd(t_ms **ms)
{
	ft_printf("%s\n", (*ms)->pwd);
	(*ms)->exit_status = 0;
	return ((*ms)->exit_status);
}
