/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:53:49 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:42:54 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

volatile int	g_signal = 0;

int	main(int ac, char **av, char **envp)
{
	t_ms				*ms;

	init_ms(&ms, envp);
	signal_global(&ms);
	(void)av;
	(void)ac;
	while (ms->is_exit == 0)
	{
		signal(SIGQUIT, SIG_IGN);
		g_signal_handler(&ms);
		ft_readcmd(&ms);
	}
	if (ms->is_exit == 1)
		free_ms(&ms);
	return (0);
}
