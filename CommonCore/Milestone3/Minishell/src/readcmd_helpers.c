#include "../includes/minishell.h"

void	handle_double_quotes_rdcmd(char **str, char **tmp, int *i)
{
	*tmp = ft_get_d_quotes(*str + *i);
	*i += ft_strlen(*tmp);
	ft_free_gnl(tmp);
}

void	handle_single_quotes_rdcmd(char **str, char **tmp, int *i)
{
	*tmp = ft_get_s_quotes(*str + *i);
	*i += ft_strlen(*tmp);
	ft_free_gnl(tmp);
}

void	handle_spaces_and_tabs_rdcmd(char **str, char **tmp, int *i)
{
	int	start;

	start = *i;
	*tmp = ft_strndup(*str, *i);
	*tmp = ft_strcjoin(*tmp, ' ');
	while ((*str)[start] && ((*str)[start] == 32 \
		|| ((*str)[start] >= 9 && (*str)[start] <= 13)))
		start++;
	*tmp = ft_strjoin_gnl(*tmp, *str + start);
	ft_free_gnl(str);
	*str = ft_strdup_free(*tmp);
}

void	skip_initial_spaces_radcmd_help(char **str, char **tmp)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '"')
			handle_double_quotes_rdcmd(str, tmp, &i);
		else if ((*str)[i] == '\'')
			handle_single_quotes_rdcmd(str, tmp, &i);
		else if ((*str)[i] == 32 || ((*str)[i] >= 9 && (*str)[i] <= 13))
			handle_spaces_and_tabs_rdcmd(str, tmp, &i);
		i++;
	}
}
