/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:53:49 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:43:32 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

int	i_string_enclosed(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len < 2)
		return (0);
	if ((str[0] == '"' && str[len - 1] == '"') || \
		(str[0] == '\'' && str[len - 1] == '\''))
		return (1);
	return (0);
}

void	ft_put_error(char *str_error, char *needle, char *result)
{
	char	*error;

	error = ft_replace_word(str_error, needle, result);
	ft_putstr_fd(error, 2);
	free(error);
}

int	has_unquoted_semicolon_or_asterisk(char *str)
{
	int	in_single_quote;
	int	in_double_quote;

	in_single_quote = 0;
	in_double_quote = 0;
	while (*str)
	{
		if (*str == '\'')
		{
			in_single_quote = 1;
			in_double_quote = 0;
		}
		else if (*str == '"')
		{
			in_double_quote = 1;
			in_single_quote = 0;
		}
		else if ((*str == ';' || *str == '*') && \
			!in_single_quote && !in_double_quote)
			return (1);
		str++;
	}
	return (0);
}

int	count_quotes(const char *str, char q)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == q)
			count++;
		str++;
	}
	return (count);
}
