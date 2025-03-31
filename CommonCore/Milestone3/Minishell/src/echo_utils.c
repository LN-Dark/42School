#include "../includes/minishell.h"

int	ft_strlen_abc(char *str, char a, char b, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == a || str[i] == b || str[i] == c || str[i] == ' ')
			break ;
		i++;
	}
	return (i);
}
