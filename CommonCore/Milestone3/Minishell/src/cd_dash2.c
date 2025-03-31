/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_dash2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:40:37 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:40:37 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cd_dash3(t_ms **ms)
{
	char	*str;

	str = ft_strjoin((*ms)->pwd, "\n");
	ft_putstr_fd(str, 1);
	free(str);
}

void	cd_home_error(t_ms **ms)
{
	ft_putstr_fd("-minishell: cd: HOME not set\n", 2);
	(*ms)->exit_status = 1;
}
