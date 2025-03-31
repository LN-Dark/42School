/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_errors_quotes1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:43:58 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:43:59 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_error_export(size_t *i, size_t l, char *input)
{
	char	*str;
	size_t	j;

	str = malloc(sizeof(char) * (ft_strlen(input) + 1));
	j = 0;
	while (l < *i)
		str[j++] = input[l++];
	str[j] = '\0';
	ft_put_error(ERROR_EXP_P, "%s", str);
	free(str);
}

void	errors_with_quotes3_2(char *input, size_t *i, int *found)
{
	if (input[*i] && (ft_isalpha(input[*i]) || ft_isdigit(input[*i]) || \
	input[*i] == '_' || input[*i] == '$' || input[*i] == '+') && !(*found) && \
	input[*i] != ' ')
		(*i)++;
	if (*found && input[*i] && input[*i] != ' ')
		(*i)++;
}

int	quotes3_1(char *input, size_t *i, int *error, int *found)
{
	if (input[*i])
		errors_with_quotes3_1(input, i, error, found);
	return (0);
}

int	quotes3_2(char *input, size_t *i, int *found)
{
	errors_with_quotes3_2(input, i, found);
	return (0);
}
