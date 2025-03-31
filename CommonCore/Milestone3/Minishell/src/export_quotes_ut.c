/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_quotes_ut.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:45:05 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:45:05 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*putbar2(char *input, int count, size_t i)
{
	char	*n_input;
	size_t	j;

	j = 0;
	n_input = malloc(sizeof(char) * (count + 1 + i));
	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '$')
			n_input[j++] = '\\';
		n_input[j++] = input [i++];
	}
	n_input[j] = '\0';
	free(input);
	return (n_input);
}

char	*putbar(char *input)
{
	size_t	i;
	int		count;
	char	*n_input;

	count = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '$')
			count++;
		i++;
	}
	if (count)
		n_input = putbar2(input, count, i);
	else
		n_input = input;
	return (n_input);
}

void	add_to_struct(t_ms **ms, char *n_input)
{
	size_t	i;
	char	**new_array;

	i = 0;
	new_array = NULL;
	if ((*ms)->export_in == NULL)
		new_array = malloc(sizeof(char *) * 2);
	else
	{
		while ((*ms)->export_in[i])
			i++;
		new_array = malloc(sizeof(char *) * (i + 2));
		i = 0;
		while ((*ms)->export_in[i])
		{
			new_array[i] = ft_strdup((*ms)->export_in[i]);
			i++;
		}
	}
	new_array[i] = n_input;
	i++;
	new_array[i] = 0;
	if ((*ms)->export_in != NULL)
		ft_free((*ms)->export_in);
	(*ms)->export_in = new_array;
}

void	add(t_ms **ms, size_t i, char *input)
{
	char	*n_input;
	size_t	j;
	size_t	h;

	h = 0;
	j = 0;
	n_input = malloc((i - (*ms)->exp_start + 1) * sizeof(char));
	while (input[h] && input[h] == ' ')
		h++;
	while (input[h] && input[h] != ' ')
	{
		n_input[j] = input[h];
		j++;
		h++;
	}
	n_input[j] = '\0';
	export_1arg(n_input, ms);
	free(n_input);
}

void	add_to_array(t_ms **ms, size_t i, char *input, int quotes)
{
	if (quotes == 1)
		add_with_s_qt(ms, i, input);
	else if (quotes == 2)
		add_with_d_qt(ms, i, input);
	else
		add(ms, i, input);
}
