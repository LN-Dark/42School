#include "../includes/minishell.h"

void	heredoc4_1(t_ms **ms)
{
	int	fd;

	if (ft_strstr((*ms)->h.n_str2, "<<") == NULL && (*ms)->hdc_nm && \
	(*ms)->here_check != 0 && ft_strstr((*ms)->h.n_str2, ">") == NULL)
		return (free((*ms)->h.n_str2));
	if (ft_strstr((*ms)->h.n_str2, "<<") == NULL && (*ms)->hdc_nm)
	{
		fd = open((*ms)->hdc_nm, O_RDONLY);
		dup2(fd, STDIN_FILENO);
		process_redirects2((*ms)->h.n_str2, ms);
		close(fd);
	}
	else if (ft_strstr((*ms)->h.n_str2, "<<") == NULL && !(*ms)->hdc_nm)
	{
		fd = open("here", O_CREAT, 777);
		close(fd);
		fd = open("here", O_RDONLY);
		dup2(fd, STDIN_FILENO);
		process_redirects2((*ms)->h.n_str2, ms);
		close(fd);
		choose_builtin("rm -f here", ms);
	}
	else
		process_redirects2((*ms)->h.n_str2, ms);
}

char	*remore_redir_eof(char *e_o_f)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(e_o_f) + 1));
	if (ft_strchr(e_o_f, '<') || ft_strchr(e_o_f, '>'))
	{
		while (e_o_f[i])
		{
			if (e_o_f[i] == '<' || e_o_f[i] == '>')
				break ;
			str[j++] = e_o_f[i++];
		}
		str[j] = '\0';
		free(e_o_f);
		return (str);
	}
	free(str);
	return (e_o_f);
}
