#include "../includes/minishell.h"

void	redi_get_str_quotes1(char *str, size_t *h, int *found1, int *found2)
{
	if (str[*h] == '\'' && !(*found1))
	{
		(*found1)++;
		(*h)++;
	}
	if (str[*h] && str[*h] == '"' && !(*found2))
	{
		(*found2)++;
		(*h)++;
	}
	if (str[*h] && str[*h] == '\'' && (*found1))
	{
		*found1 = 0;
		(*h)++;
	}
	if (str[*h] && str[*h] == '"' && !(*found2))
	{
		*found2 = 0;
		(*h)++;
	}
}

void	redi_get_str_quotes2(char *str, size_t *h, size_t *i, char **str2)
{
	while (str[*h])
	{
		if (str[*h] == '\'')
			break ;
		(*str2)[(*i)++] = str[(*h)++];
	}
	(*h)++;
	while (str[*h] && str[*h] != '\'')
		(*str2)[(*i)++] = str[(*h)++];
}

char	*redi_get_str_quotes0(char *str, size_t *h, t_ms**ms, int found1)
{
	char	*str2;
	size_t	i;

	i = 0;
	str2 = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[*h])
	{
		redi_get_str_quotes1(str, h, &found1, &(*ms)->found2q);
		if (str[*h] && str[*h] == '$' && found1)
		{
			(*ms)->not_expand = 0;
			redi_get_str_quotes2(str, h, &i, &str2);
			break ;
		}
		else if (str[*h] && str[*h] == '$')
		{
			while (str[*h] && str[*h] != ' ' && str[*h] != '"')
				str2[i++] = str[(*h)++];
			break ;
		}
		if (str[*h] != '"' && str[*h] != '\'' )
			str2[i++] = str[(*h)++];
	}
	str2[i] = '\0';
	return (str2);
}

char	*redi_get_str_quotes(char *str, size_t *h, t_ms**ms)
{
	int		found1;

	found1 = 0;
	(*ms)->found2q = 0;
	return (redi_get_str_quotes0(str, h, ms, found1));
}

char	*get_str_and_check(t_ms **ms, size_t *h, char *cmd, int nb)
{
	char	*str;
	char	*str2;

	if (file_no_name(cmd))
		return (NULL);
	str2 = ft_strdup(cmd);
	str = get_str_redi_out(cmd, ms, str2, h);
	str2 = get_str(str, '>', nb, ms);
	free(str);
	str = check_other_redir(str2);
	if (ft_strchr(cmd, '\'') == NULL)
		str = add_end(str, cmd);
	return (str);
}
