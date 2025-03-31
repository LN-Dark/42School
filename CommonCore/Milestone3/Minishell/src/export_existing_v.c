#include "../includes/minishell.h"

void	export_exv2_1(char *var_name, t_ms **ms, char *ex_var_name)
{
	char	*str;
	char	*str2;

	str = ft_strjoin(var_name, "=");
	str2 = ft_strjoin("export ", str);
	ft_free((*ms)->export);
	(*ms)->export = NULL;
	handle_export (str2, ms);
	free(str2);
	free(ex_var_name);
	free(str);
}

void	export_existing_v2_2(char *str, char *input, char *ex_var_name, \
t_ms **ms)
{
	char	*var_name;
	char	*str2;

	var_name = (*ms)->var_name;
	str = trim_str_export(ms);
	str = ft_strtrim_free(str, "=");
	if (input[0] != '\0')
		str2 = ft_strjoin(input, str);
	else
		str2 = ft_strdup(str);
	free(str);
	str = ft_strjoin("=", str2);
	free(str2);
	str2 = ft_strjoin(var_name, str);
	free(str);
	str = ft_strjoin("export ", str2);
	ft_free((*ms)->export);
	(*ms)->export = NULL;
	handle_export (str, ms);
	free_exv(str, str2, ex_var_name);
}

void	export_existing_v2(char *var_name, char *ex_var_name, t_ms **ms, \
char *input)
{
	char	*str;
	int		check;

	(*ms)->var_name = var_name;
	check = 0;
	str = NULL;
	if ((*ms)->tmpvar)
		str = search_tmpvar(ms, ex_var_name);
	input = get_concat_in(input);
	if (check_export_variable(ex_var_name, str))
	{
		(*ms)->p = get_i_ex(ms, &check, ex_var_name);
		if (check)
			export_existing_v2_2(str, input, ex_var_name, ms);
		else
			export_exv2_1(var_name, ms, ex_var_name);
	}
	else
		export_existing_v3(var_name, str, ms, ex_var_name);
	free(var_name);
	free(input);
	if (str != NULL)
		free(str);
}

char	*get_var_name(char *input, char *ex_var_name, int *check)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	*(check) = 0;
	if (input[i] == '$')
		i++;
	while (input[i])
	{
		if (input[i] == '=')
			break ;
		i++;
	}
	if (input[i])
		i++;
	check_for_exp(check, i, input);
	while (input[i])
		ex_var_name[j++] = input[i++];
	ex_var_name[j] = '\0';
	return (ex_var_name);
}

void	export_existing_v(char *input, t_ms **ms)
{
	size_t	i;
	size_t	j;
	char	*var_name;
	char	*ex_var_name;
	int		check;

	check = 0;
	j = 0;
	i = 0;
	while (input[i] && input[i] != '=')
		i++;
	while (j < i)
		j++;
	var_name = get_var_name2(j, input, i);
	j = 0;
	var_name = get_new_var_name(var_name, ms);
	if (input[i])
		while (input[++i])
			j++;
	ex_var_name = malloc(sizeof(char) * (j + 1));
	ex_var_name = get_var_name(input, ex_var_name, &check);
	if (check)
		export_existing_v2(var_name, ex_var_name, ms, input);
	else
		concat_and_export(var_name, ex_var_name, ms);
}
