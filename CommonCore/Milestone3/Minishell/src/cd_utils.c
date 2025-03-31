/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:41:42 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:41:42 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*trim_quotes(char *input, int size)
{
	char	*new_input;
	int		i;

	i = 0;
	new_input = malloc(size * sizeof(char));
	while (i < size - 1)
	{
		new_input[i] = input[i];
		i++;
	}
	new_input[i] = '\0';
	return (new_input);
}

char	*remove_quotes2(char *input)
{
	ft_putstr_fd("Unclosed quotes\n", 2);
	input = NULL;
	return (input);
}

char	*remove_quotes(char *input)
{
	int		size;
	int		check;
	char	*input2;

	check = 0;
	input2 = input;
	if (*input == '"')
	{
		input++;
		check = 1;
	}
	else if (*input == '\'' )
		input++;
	else
		return (input);
	size = ft_strlen(input);
	if (input[size - 1] == '\'' && !check)
		input = trim_quotes(input, size);
	else if (input[size - 1] == '"' && check)
		input = trim_quotes(input, size);
	else
		input = remove_quotes2(input);
	return (free(input2), input);
}

int	check_input_args(char *input, t_ms **ms)
{
	char	**input2;

	input2 = ft_split(input, ' ');
	if (input[0])
	{
		if (input2[1] != NULL && ft_strchr(input2[1], '"') == NULL \
		&& ft_strchr(input2[1], '\'') == NULL)
		{
			(*ms)->exit_status = 1;
			ft_free(input2);
			return (1);
		}
	}
	ft_free(input2);
	return (0);
}

char	*remove_spaces_end(char	*input2)
{
	char	**input;
	char	*new_input;

	if (input2[0] != '\0')
	{
		input = ft_split(input2, ' ');
		new_input = ft_strdup(input[0]);
		return (ft_free(input), new_input);
	}
	return (ft_strdup(input2));
}
