#include "../includes/minishell.h"

char	*trim_str_export(t_ms **ms)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = 0;
	str = malloc(sizeof(char) * (ft_strlen((*ms)->envp[(*ms)->p]) + 1));
	i = 0;
	while ((*ms)->envp[(*ms)->p][i] && (*ms)->envp[(*ms)->p][i] != '=')
		i++;
	if ((*ms)->envp[(*ms)->p][i] && (*ms)->envp[(*ms)->p][i] == '=')
	{
		i++;
		while ((*ms)->envp[(*ms)->p][i])
			str[j++] = (*ms)->envp[(*ms)->p][i++];
	}
	str[j] = '\0';
	return (str);
}
