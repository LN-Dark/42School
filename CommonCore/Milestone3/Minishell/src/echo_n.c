#include "../includes/minishell.h"

int	process_n_option(char **str_comp, int *i, t_check_option_n *opt)
{
	opt->h = 2;
	while (str_comp[opt->j][opt->h] && str_comp[opt->j][opt->h] == 'n')
		opt->h++;
	if (str_comp[opt->j][opt->h] != '\0')
	{
		if (str_comp[opt->j][opt->h] != 'n' && str_comp[opt->j][opt->h + 1] &&
			str_comp[opt->j][opt->h + 1] != '\0')
			return (1);
		else
			return (opt->display_newline);
	}
	opt->display_newline = 0;
	(*i) += opt->len_init + 1;
	return (-1);
}

int	check_option_n(char **str_comp, int *i, t_check_option_n opt)
{
	int	result;

	while (str_comp[opt.j])
	{
		opt.len_init = ft_strlen(str_comp[opt.j]);
		str_comp[opt.j] = ft_remove_special_chars(str_comp[opt.j]);
		if (str_comp[opt.j][0] && str_comp[opt.j][0] == '-' &&
			str_comp[opt.j][1] && str_comp[opt.j][1] == 'n')
		{
			result = process_n_option(str_comp, i, &opt);
			if (result != -1)
				return (result);
		}
		else
			return (opt.display_newline);
		opt.j++;
	}
	return (opt.display_newline);
}

int	check_display_newline(char *input, int *i)
{
	char				**str_comp;
	int					result;
	t_check_option_n	opt;

	opt.j = 1;
	opt.display_newline = 1;
	str_comp = ft_split(input, ' ');
	if (!str_comp)
		return (1);
	result = check_option_n(str_comp, i, opt);
	return (ft_free(str_comp), result);
}
