#include "../includes/minishell.h"

char	**expand_heredoc2_1(size_t i, char **str, char **str2, t_ms **ms)
{
	while (str[i])
	{
		if (ft_strchr(str[i], '$') != NULL)
		{
			str2[i] = get_expansion(str[i], ms);
			while (ft_strchr(str2[i], '$') != NULL)
				str2[i] = get_expansion(str2[i], ms);
		}
		else
			str2[i] = ft_strdup(str[i]);
		i++;
	}
	str2[i] = 0;
	return (str2);
}

char	*expand_heredoc2(t_ms **ms, char *str3)
{
	char	**str;
	size_t	i;
	char	**str2;
	char	*n_str;

	i = 0;
	str = ft_split(str3, '\n');
	while (str[i])
		i++;
	str2 = malloc(sizeof(char *) * (i + 1));
	i = 0;
	str2 = expand_heredoc2_1(i, str, str2, ms);
	ft_free(str);
	n_str = n_str_heredoc(str2, 1);
	free(str3);
	ft_free(str2);
	return (n_str);
}

void	expand_heredoc1(size_t i, char **str, char **str2, t_ms **ms)
{
	char	*n_str;
	char	*n_str2;

	while (str[i])
	{
		if (ft_strchr(str[i], '$') != NULL)
		{
			str2[i] = get_expansion(str[i], ms);
			while (ft_strchr(str2[i], '$') != NULL)
			{
				n_str2 = str2[i];
				str2[i] = get_expansion(str2[i], ms);
				free(n_str2);
			}
		}
		else
			str2[i] = ft_strdup(str[i]);
		i++;
	}
	str2[i] = 0;
	n_str = n_str_heredoc(str2, 0);
	free((*ms)->h.bff2);
	(*ms)->h.bff2 = n_str;
}

char	*expand_heredoc(t_ms **ms, int n, char *str3)
{
	char	**str;
	size_t	i;
	char	**str2;
	char	*n_str;

	i = 0;
	if (n == 0)
		str = ft_split((*ms)->h.bff2, '\n');
	else
	{
		n_str = expand_heredoc2(ms, str3);
		return (n_str);
	}
	while (str[i])
		i++;
	str2 = malloc(sizeof(char *) * (i + 1));
	i = 0;
	expand_heredoc1(i, str, str2, ms);
	ft_free(str);
	ft_free(str2);
	return (NULL);
}
