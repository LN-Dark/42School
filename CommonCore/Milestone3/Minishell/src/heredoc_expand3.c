#include "../includes/minishell.h"

char	*get_the_rest2(char *n_str, char *str2, int n)
{
	char	*n_str2;

	if (n)
	{
		n_str2 = ft_strjoin(str2, n_str);
		free(n_str);
	}
	else
		n_str2 = n_str;
	return (n_str2);
}

char	*get_the_rest(char *str, size_t j, int n, char *str2)
{
	size_t	i;
	size_t	h;
	char	*n_str;
	char	*n_str2;

	i = 0;
	h = 0;
	while (str[j] && str[j] != ' ' && str[j] != '/')
		j++;
	if (str[j])
	{
		if (str[j] == ' ')
			j++;
	}
	else
		return (str2);
	i = j;
	while (str[j])
		j++;
	n_str = malloc(sizeof(char) * (j - i + 1));
	while (i < j)
		n_str[h++] = str[i++];
	n_str[h] = '\0';
	n_str2 = get_the_rest2(n_str, str2, n);
	return (free(str2), n_str2);
}

char	*get_str_no_exp(char *str)
{
	size_t	i;
	size_t	j;
	char	*str2;

	i = 0;
	str2 = NULL;
	while (str[i] && str[i] != '$')
		i++;
	j = ++i;
	if (i > 0)
	{
		str2 = malloc(sizeof(char) * (i + 1));
		i = 0;
		while (str[i] && str[i] != '$')
		{
			str2[i] = str[i];
			i++;
		}
		str2[i] = '\0';
	}
	if (str2 == NULL)
		str2 = get_the_rest(str, j, 0, str2);
	else
		str2 = get_the_rest(str, j, 1, str2);
	return (str2);
}

char	*append_to_var(char *n_str, char *str)
{
	char	*str3;
	size_t	i;
	size_t	j;
	size_t	h;

	j = 0;
	i = 0;
	h = 0;
	str3 = malloc(sizeof(char) * (ft_strlen(n_str) + ft_strlen(str) + 1));
	while (str[i] && str[i] != '$')
		str3[j++] = str[i++];
	while (str[i] && str[i] != ' ')
		i++;
	while (n_str[h])
		str3[j++] = n_str[h++];
	while (str[i])
		str3[j++] = str[i++];
	str3[j] = '\0';
	free(n_str);
	return (str3);
}

char	*get_expansion(char *str, t_ms **ms)
{
	size_t	i;
	size_t	j;
	size_t	h;
	char	*n_str;
	char	*n_str2;

	i = 0;
	h = 0;
	while (str[i] && str[i] != '$')
		i++;
	j = ++i;
	while (str[j] && str[j] != ' ' && str[j] != '/')
		j++;
	n_str = malloc(sizeof(char) * (j - i + 1));
	while (i < j)
		n_str[h++] = str[i++];
	n_str[h] = '\0';
	n_str = get_var(n_str, ms);
	if (n_str == NULL)
		n_str2 = get_str_no_exp(str);
	else
		n_str2 = append_to_var(n_str, str);
	return (n_str2);
}
