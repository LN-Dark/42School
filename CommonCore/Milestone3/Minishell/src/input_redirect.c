#include "../includes/minishell.h"

void	process_redirects2(char *command, t_ms **ms)
{
	int		redirect_type;

	redirect_type = 0;
	(*ms)->cmd = ft_strtrim(command, " ");
	free(command);
	redirect_type = handle_redi((*ms)->cmd, ms, redirect_type);
	if (redirect_type == 0)
		choose_builtin((*ms)->cmd, ms);
	if ((*ms)->cmd)
		free((*ms)->cmd);
	(*ms)->cmd = NULL;
}

void	child_input(t_ms **ms, char *cmd_trim)
{
	char	*str;
	int		fd;
	char	*str2;

	if (file_no_name(cmd_trim))
	{
		free_ms(ms);
		exit(2);
	}
	str = get_str(cmd_trim, '<', 1, ms);
	str = check_other_redir(str);
	fd = open(str, O_RDONLY, 0777);
	if (fd == -1)
		fd_error(ms, str, 1);
	free(str);
	remove_redir(cmd_trim, '<', 1, ms);
	dup2(fd, STDIN_FILENO);
	close(fd);
	free((*ms)->cmd);
	(*ms)->cmd = NULL;
	str2 = ft_strdup((*ms)->str_redir);
	free((*ms)->str_redir);
	(*ms)->str_redir = NULL;
	process_redirects2(str2, ms);
	free_ms(ms);
}

void	input_redirect(t_ms **ms, char *cmd_trim)
{
	pid_t	pid;
	int		i;
	int		j;
	int		status;

	i = 0x7F;
	j = 0xFF;
	status = 0;
	pid = fork();
	if (pid == 0)
		child_input(ms, cmd_trim);
	else
	{
		waitpid(pid, &status, 0);
		if (status & j)
			(*ms)->exit_status = status & i;
		else
			(*ms)->exit_status = (status >> 8) & j;
	}
}
