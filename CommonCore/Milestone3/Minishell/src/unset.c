/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:53:49 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:43:39 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void	aply_unset(char *input, t_ms **ms, char **envp)
{
	size_t	i;
	size_t	j;
	char	**new_envp;

	i = 0;
	while (envp[i])
		i++;
	new_envp = malloc(i * sizeof(char *));
	i = 0;
	while (ft_strnstr(envp[i], input, ft_strlen(input)) == NULL)
	{
		new_envp[i] = ft_strdup(envp[i]);
		i++;
	}
	j = i + 1;
	while (envp[j])
	{
		new_envp[i] = ft_strdup(envp[j]);
		i++;
		j++;
	}
	new_envp[i] = 0;
	free_envp(ms);
	(*ms)->envp = new_envp;
	(*ms)->exit_status = 0;
}

void	unset_1arg(char *input, t_ms **ms)
{
	size_t	i;
	char	**envp;
	int		check;
	char	*input2;

	check = 0;
	envp = (*ms)->envp;
	i = 0;
	input2 = ft_strtrim(input, "\n");
	while (*input2 == ' ')
		input2++;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], input2, ft_strlen(input2)) != NULL)
		{
			check = 1;
			break ;
		}
		i++;
	}
	if (check)
		aply_unset(input2, ms, envp);
	else
		(*ms)->exit_status = 0;
	free(input2);
}

char	*remove_unset(char *input, t_ms **ms)
{
	char	*str;
	char	*str2;
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	str = malloc(sizeof(char) * (ft_strlen(input) + 1));
	while (input[j])
	{
		if (input[j] == '"' && (input[j + 1] == '\0' || input[j + 1] == ' ' \
		|| ft_isalpha(input[j + 1])))
			j++;
		if (input[j] == '\'' && (input[j + 1] == '\0' || input[j + 1] == ' ' \
		|| ft_isalpha(input[j + 1])))
			j++;
		if (input[j])
			str[k++] = input[j++];
	}
	str[k] = '\0';
	if (ft_strchr(str, '$') != NULL)
		str2 = expander(str, ms);
	else
		str2 = str;
	return (str2);
}

void	unset(char *input, t_ms **ms)
{
	size_t	i;
	char	**input2;
	char	*input_trim;
	char	*input3;

	i = 0;
	while (input[i])
	{
		if (input[i] == '-')
			return ;
		i++;
	}
	input = remove_1st_word(input);
	input_trim = ft_strtrim(input, "\n");
	input3 = remove_unset(input_trim, ms);
	input2 = ft_split(input3, ' ');
	i = 0;
	while (input2[i])
		unset_1arg(input2[i++], ms);
	ft_free(input2);
	free(input_trim);
	free(input3);
}

char	*remove_1st_word(char *string)
{
	while (*string && *string == ' ')
		string++;
	while (*string && *string != ' ')
		string++;
	while (*string && *string == ' ')
		string++;
	return (string);
}
