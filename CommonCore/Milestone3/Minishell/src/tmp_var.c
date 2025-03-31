#include "../includes/minishell.h"

void	temp_array(char *input, t_ms **ms)
{
	char	**tmpvar;
	size_t	i;

	if ((*ms)->tmpvar == NULL)
	{
		tmpvar = malloc(sizeof(char *) * 2);
		tmpvar[0] = ft_strdup(input);
		tmpvar[1] = 0;
	}
	else
	{
		i = 0;
		while ((*ms)->tmpvar[i])
			i++;
		tmpvar = malloc(sizeof(char *) * (i + 2));
		while ((*ms)->tmpvar[i])
		{
			tmpvar[i] = (*ms)->tmpvar[i];
			i++;
		}
		tmpvar[i] = ft_strdup(input);
		i++;
		tmpvar[i] = 0;
	}
}
