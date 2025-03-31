#include "../includes/minishell.h"

char	*ft_strtrim_start(char *s1, char *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	str = (char *)ft_calloc((j - i + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, &s1[i], j - i + 1);
	return (str);
}

int	check_mini_pipe(char *input, t_ms **ms)
{
	int		found;
	char	*str;

	found = 0;
	if (ft_strstr(input, "./minishell"))
	{
		while (*input && *input != '.' && \
		*input + 1 != '/' && *input + 2 != 'm')
			input++;
		if (ft_strnstr(input, "./minishell", 11) != NULL)
		{
			found++;
			str = ft_strtrim_start(input, "./minishell");
			if (ft_strstr(str, "./minishell"))
			{
				free(str);
				pipe_mini(ms);
				return (1);
			}
			free(str);
		}
	}
	return (0);
}

void	gofowardpipes(t_ms **ms, char *cmd)
{
	(*ms)->i++;
	while (cmd[(*ms)->i] && cmd[(*ms)->i] != '"')
		(*ms)->i++;
	(*ms)->i++;
}
