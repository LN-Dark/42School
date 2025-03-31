/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:43:28 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:43:28 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_extracmd2(char *cmd, size_t h, size_t i)
{
	char	*input2;

	input2 = malloc(sizeof(char *) * (ft_strlen(cmd)));
	while (cmd[i] && cmd[i] != '$')
	{
		input2[i] = cmd[i];
		i++;
	}
	h = i;
	h++;
	while (cmd[h] && cmd[h] != ' ')
		h++;
	while (cmd[h])
		input2[i++] = cmd[h++];
	input2[i] = '\0';
	return (input2);
}

char	*get_extracmd3(char *cmd, char *input, size_t i, size_t j)
{
	char	*input2;
	size_t	h;

	input2 = malloc(sizeof(char *) * (ft_strlen(input) + ft_strlen(cmd)));
	while (cmd[i] && cmd[i] != '$')
	{
		input2[i] = cmd[i];
		i++;
	}
	if (cmd[i] == '$' || cmd[i + 1] != '\0')
		h = i + 1;
	else
		h = i;
	while (input[j])
		input2[i++] = input[j++];
	while (cmd[h] && cmd[h] != ' ')
		h++;
	while (cmd[h])
		input2[i++] = cmd[h++];
	input2[i] = '\0';
	return (input2);
}

char	*get_extracmd1(char *cmd, char *input)
{
	char	*input2;
	size_t	i;
	size_t	j;
	size_t	h;

	i = 0;
	h = 0;
	j = 0;
	if (input == NULL)
		input2 = get_extracmd2(cmd, h, i);
	else
		input2 = get_extracmd3(cmd, input, i, j);
	free(input);
	return (input2);
}
