/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:31:03 by pbranco-          #+#    #+#             */
/*   Updated: 2024/11/14 14:46:10 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	signal_convert(int signal)
{
	static char	*str = NULL;
	static int	c = 0;
	static int	bit = 0;

	if (signal == SIGUSR1)
		c = c | (1 << bit);
	bit += 1;
	if (bit == 8)
	{
		if (c == '\0')
		{
			ft_printf("%s\n", str);
			ft_free_gnl(&str);
			str = NULL;
		}
		else
			str = ft_strcjoin(str, c);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, signal_convert);
		signal(SIGUSR2, signal_convert);
	}
}
