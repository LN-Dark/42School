#include "../includes/minishell.h"

void	cd_dash3(t_ms **ms)
{
	char	*str;

	str = ft_strjoin((*ms)->pwd, "\n");
	ft_putstr_fd(str, 1);
	free(str);
}

void	cd_home_error(t_ms **ms)
{
	ft_putstr_fd("-minishell: cd: HOME not set\n", 2);
	(*ms)->exit_status = 1;
}
