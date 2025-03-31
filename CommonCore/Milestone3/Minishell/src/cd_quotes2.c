/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_quotes2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:41:26 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:41:27 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*cd_quotes2(t_ms **ms, char *input, size_t *i, int *check)
{
	char	*new_str;

	new_str = NULL;
	if (input[(*i)] == '$' && (*check) == 2)
		new_str = expand_heredoc(ms, 1, ft_strtrim(input, "\""));
	return (new_str);
}
