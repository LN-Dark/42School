#include "../includes/minishell.h"

char	*get_var_without_exp(char *var_name)
{
	size_t	i;
	char	*str;

	i = 0;
	while (var_name[i] && var_name[i] != '$')
		i++;
	str = malloc(sizeof(char) * i + 1);
	i = 0;
	while (var_name[i] && var_name[i] != '$')
	{
		str[i] = var_name[i];
		i++;
	}
	str[i] = '\0';
	free (var_name);
	return (str);
}

char	*get_new_var_name(char *var_name, t_ms **ms)
{
	int		check;
	size_t	i;
	int		found;

	found = 0;
	check = 0;
	i = 0;
	while (var_name[i])
	{
		if (var_name[i] == '$' && check == 0)
		{
			found++;
			break ;
		}
		if (var_name[i] == '=')
			check++;
		i++;
	}
	if (found)
		var_name = expand_heredoc(ms, 1, var_name);
	return (var_name);
}

char	*get_var_name2(size_t j, char *input, size_t i)
{
	char	*var_name;

	var_name = malloc(sizeof(char) * (j + 1));
	j = 0;
	while (j < i)
	{
		var_name[j] = input[j];
		j++;
	}
	var_name[j] = '\0';
	return (var_name);
}

int	*check_for_exp(int *check, size_t i, char *input)
{
	*(check) = 0;
	if (input[i])
	{
		while (input[i])
		{
			if (input[i] == '$')
				*(check) = 1;
			i++;
		}
	}
	return (check);
}

void	concat_and_export(char *var_name, char *ex_var_name, t_ms **ms)
{
	char	*str;
	char	*str2;

	str = ft_strjoin(var_name, "=");
	free(var_name);
	str2 = ft_strjoin(str, ex_var_name);
	free(str);
	free(ex_var_name);
	str = ft_strjoin("export ", str2);
	free(str2);
	ft_free((*ms)->export);
	(*ms)->export = NULL;
	handle_export(str, ms);
	free(str);
}
