#include "../includes/minishell.h"

int	search_home(t_ms **ms)
{
	char	*str;
	size_t	i;

	i = 0;
	str = "HOME";
	while ((*ms)->envp[i])
	{
		if (ft_strstr_1((*ms)->envp[i], str) != NULL )
			return (1);
		i++;
	}
	return (0);
}

void	cd_home2(t_ms **ms)
{
	char	*new_pwd;

	if (search_home(ms))
	{
		if (search_pwd(ms, 0) || (*ms)->cd == 1)
		{
			new_pwd = ft_strjoin("export OLDPWD=", (*ms)->pwd);
			handle_export(new_pwd, ms);
			free(new_pwd);
		}
		free((*ms)->oldpwd);
		(*ms)->oldpwd = ft_strdup((*ms)->pwd);
		chdir((*ms)->home);
		if (search_pwd(ms, 1))
		{
			new_pwd = ft_strjoin("export PWD=", (*ms)->home);
			handle_export(new_pwd, ms);
			free(new_pwd);
		}
		free((*ms)->pwd);
		(*ms)->pwd = ft_strdup((*ms)->home);
		(*ms)->exit_status = 0;
	}
	else
		cd_home_error(ms);
}

void	cd_home(t_ms **ms, char *input)
{
	char	*new_pwd;

	if (ft_strcmp(input, "~") == 0)
	{
		if (search_pwd(ms, 0) || (*ms)->cd == 1)
		{
			new_pwd = ft_strjoin("export OLDPWD=", (*ms)->pwd);
			handle_export(new_pwd, ms);
			free(new_pwd);
		}
		chdir((*ms)->home);
		if (search_pwd(ms, 1))
		{
			new_pwd = ft_strjoin("export PWD=", (*ms)->home);
			handle_export(new_pwd, ms);
			free(new_pwd);
		}
		free((*ms)->pwd);
		(*ms)->pwd = ft_strdup((*ms)->home);
		(*ms)->exit_status = 0;
	}
	else
		cd_home2(ms);
}

void	cd2(char *input, t_ms **ms)
{
	if (ft_strcmp(input, "-") == 0)
		cd_dash(ms);
	else if (ft_strchr(input, '"') != NULL || (ft_strchr(input, '\'') != NULL))
		cd_quotes(ms, input);
	else if (ft_strchr(input, '$') != NULL)
		cd_ex_v(input, ms);
	else if (ft_strchr(input, '/') == NULL)
		cd_no_slash(ms, input);
	else if (ft_strchr(input, '/') != NULL)
		cd_slash(input, ms);
}

void	builtin_cd(char *input, t_ms **ms)
{
	char	*input2;

	(*ms)->cd++;
	input2 = remove_1st_word(input);
	input = remove_spaces_end(input2);
	if (check_input_args(input2, ms) == 1)
	{
		ft_put_error(ERROR_CD, "%s", "cd");
		free(input);
		(*ms)->exit_status = 1;
		return ;
	}
	if (!input)
		return ;
	if (ft_strcmp(input, "..") == 0)
		handle_cd_dot(ms);
	else if (ft_strcmp(input, ".") == 0)
		(*ms)->exit_status = 0;
	else if (ft_strcmp(input, "~") == 0 || ft_strcmp(input, "") == 0)
		cd_home(ms, input);
	else
		cd2(input, ms);
	free(input);
}
