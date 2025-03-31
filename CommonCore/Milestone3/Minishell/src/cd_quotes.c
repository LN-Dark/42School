/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:41:21 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:41:21 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cd_quotes3(t_ms **ms, char *new_str, char *str)
{
	char	*str2;

	str2 = ft_strjoin("cd ", new_str);
	builtin_cd(str2, ms);
	free(str);
	free(new_str);
	free (str2);
}

void	cd_quotes4(t_ms **ms, char *input, char *str)
{
	char	*str2;

	if (ft_strlen(str) == 0)
		return (free(str));
	str2 = ft_strjoin("cd ", str);
	if (ft_strchr(str2, '$') != NULL)
	{
		if (ft_strchr(input, '/') == NULL)
			cd_no_slash(ms, str);
		else
			cd_slash(str, ms);
		free(str);
	}
	else
	{
		builtin_cd(str2, ms);
		free(str);
	}
	free (str2);
}

void	cd_quotes1(char *input, size_t *i, int *check)
{
	if (input[*i] == '"' && !(*check))
	{
		*check = 2;
		(*i)++;
	}
	if (input[*i] && input[*i] == '\'' && !(*check))
	{
		*check = 1;
		(*i)++;
	}
}

void	cd_quotes1_1(char *input, size_t *i, int *check)
{
	if (input[*i] == '"' && (*check) == 2)
	{
		(*check) = 0;
		(*i)++;
	}
	if (input[*i] == '\'' && (*check) == 1)
	{
		(*check) = 0;
		(*i)++;
	}
}

void	cd_quotes(t_ms **ms, char *input)
{
	size_t	i;
	size_t	j;
	int		check;
	char	*str;
	char	*new_str;

	j = 0;
	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(input) + 1));
	check = 0;
	while (input[i])
	{
		cd_quotes1(input, &i, &check);
		new_str = cd_quotes2(ms, input, &i, &check);
		if (new_str != NULL)
			break ;
		cd_quotes1_1(input, &i, &check);
		if (input[i])
			str[j++] = input[i++];
	}
	str[j] = '\0';
	if (new_str != NULL)
		cd_quotes3(ms, new_str, str);
	else
		cd_quotes4(ms, input, str);
}
