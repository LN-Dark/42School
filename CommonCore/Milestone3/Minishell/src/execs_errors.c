#include "../includes/minishell.h"

int	isdir(char *input)
{
	DIR		*new_dir;
	int		check;

	check = 0;
	new_dir = opendir(input);
	if (new_dir != NULL)
		check++;
	closedir(new_dir);
	return (check);
}

int	execs_error(char *command, t_ms **ms)
{
	struct stat	sfile_stat;

	if (ft_strchr(command, '/') != NULL)
	{
		if (isdir(command) && ft_strchr(command, '/') != NULL)
		{
			ft_put_error(ERROR_IS_DIR, "%s", command);
			(*ms)->exit_status = 126;
			return (1);
		}
	}
	if (stat(command, &sfile_stat) == 0)
	{
		if (access(command, X_OK) < 0 && access(command, R_OK) < 0)
		{
			ft_put_error(ERROR_PERMS, "%s", command);
			(*ms)->exit_status = 126;
			return (1);
		}
	}
	return (0);
}
