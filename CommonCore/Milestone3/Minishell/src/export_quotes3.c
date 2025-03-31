#include "../includes/minishell.h"

void	add_with_d_qt2(t_ms **ms, size_t h, char *n_input)
{
	n_input[h] = '\0';
	if (ft_strchr(n_input, '$') != NULL)
		n_input = expander(n_input, ms);
	export_1arg(n_input, ms);
	free(n_input);
}

void	add_with_d_qt(t_ms **ms, size_t i, char *input)
{
	char	*n_input;
	size_t	k;
	size_t	h;

	k = (*ms)->exp_start;
	h = 0;
	n_input = malloc(sizeof(char) * (1 + (i - (*ms)->exp_start)));
	if (input[k] == '\'' || input[k] == '"')
		k++;
	while (input[k] == ' ')
		k++;
	while (k < i)
	{
		if (input[k] == '"')
			k++;
		if (input[k] != '"')
			n_input[h++] = input[k++];
		if (input[k] == '"' && i - k == 0)
		{
			k++;
			break ;
		}
	}
	add_with_d_qt2(ms, h, n_input);
}
