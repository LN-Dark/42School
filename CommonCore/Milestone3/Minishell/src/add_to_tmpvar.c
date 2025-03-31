#include "../includes/minishell.h"

int	get_checktmp(t_ms **ms, char *n_str)
{
	int		check;
	size_t	i;
	char	*str;

	str = malloc(sizeof(char) * ft_strlen(n_str));
	i = 0;
	while (n_str[i] && n_str[i] != '=')
	{
		str[i] = n_str[i];
		i++;
	}
	str[i] = '\0';
	i = 0;
	check = 0;
	while ((*ms)->envp[i])
	{
		if (ft_strstr_1((*ms)->envp[i], str) != NULL && str[0] != '\0')
		{
			check = 1;
			break ;
		}
		(i)++;
	}
	free(str);
	return (check);
}

void	add_to_tmp2(char *input, t_ms **ms, char **str)
{
	char	**str1;	

	if ((*ms)->tmpvar == NULL)
	{
		str1 = malloc(sizeof(char *) * 2);
		str1[0] = ft_strdup(str[0]);
		str1[1] = 0;
		(*ms)->tmpvar = str1;
	}
	else
		addtmp(input, ms);
}

void	add_to_tmp(char *input, t_ms **ms)
{
	size_t	i;
	int		check;

	i = 1;
	check = 0;
	(*ms)->str_add_to_tmp = ft_split(input, ' ');
	while ((*ms)->str_add_to_tmp[i] != NULL)
	{
		(*ms)->input_tmp = ft_strdup((*ms)->str_add_to_tmp[i]);
		handle_input(ms, 2);
		i++;
	}
	check = get_checktmp(ms, (*ms)->str_add_to_tmp[0]);
	if (check)
		export_1arg((*ms)->str_add_to_tmp[0], ms);
	else
		add_to_tmp2(input, ms, (*ms)->str_add_to_tmp);
	ft_free((*ms)->str_add_to_tmp);
}

void	handle_quotes(char *input, t_ms **ms)
{
	char	*input2;

	input2 = remove_quotes_execute(input);
	add_to_tmp(input2, ms);
}

void	add_tmp_var1(char *input, t_ms **ms)
{
	size_t	i;
	int		sq;
	int		dq;

	sq = 0;
	dq = 0;
	i = 0;
	while (input[i++])
	{
		if (input[i] == '\'')
			sq++;
		if (input[i] == '"')
			dq++;
	}
	if (sq % 2 != 0 && dq % 2 != 0)
	{
		ft_putstr_fd(ft_replace_word("Unclosed quotes", "%s", input), 2);
		(*ms)->exit_status = 1;
		return ;
	}
	if (sq == 0 && dq == 0)
		add_to_tmp(input, ms);
	else
		handle_quotes(input, ms);
}
