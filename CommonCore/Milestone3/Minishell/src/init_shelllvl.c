/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shelllvl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 08:55:03 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:40:37 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

void	init_shelllvl2(t_ms **ms, size_t i)
{
	char	*str;
	char	*n_str;
	int		nb;

	n_str = ft_strtrim((*ms)->envp[i], "SHLVL=");
	nb = ft_atoi(n_str);
	free(n_str);
	nb++;
	str = ft_itoa(nb);
	n_str = ft_strjoin("SHLVL=", str);
	free(str);
	export_1arg(n_str, ms);
	free(n_str);
}

void	init_shelllvl(t_ms **ms)
{
	char	*str;
	int		found;
	size_t	i;

	i = 0;
	str = "SHLVL";
	found = 0;
	if ((*ms)->envp)
	{
		while ((*ms)->envp[i])
		{
			if (ft_strstr_1((*ms)->envp[i], str) != NULL)
			{
				found = 1;
				break ;
			}
			i++;
		}
		if (found)
			init_shelllvl2(ms, i);
	}
}
