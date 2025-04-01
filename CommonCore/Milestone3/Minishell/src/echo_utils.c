/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:42:10 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 13:48:55 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strlen_abc(char *str, char a, char b, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == a || str[i] == b || str[i] == c || str[i] == ' ')
			break ;
		i++;
	}
	return (i);
}

int	ft_strlen_dolar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalpha(str[i]))
			break ;
		i++;
	}
	return (i);
}
