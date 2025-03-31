#include "../includes/minishell.h"

char	*cd_quotes2(t_ms **ms, char *input, size_t *i, int *check)
{
	char	*new_str;

	new_str = NULL;
	if (input[(*i)] == '$' && (*check) == 2)
		new_str = expand_heredoc(ms, 1, ft_strtrim(input, "\""));
	return (new_str);
}
