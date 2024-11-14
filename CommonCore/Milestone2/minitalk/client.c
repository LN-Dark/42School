/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:31:09 by pbranco-          #+#    #+#             */
/*   Updated: 2024/11/14 14:47:49 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	ft_byte_convert(unsigned char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				break ;
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				break ;
		}
		c >>= 1;
		bit++;
		usleep(100);
	}
}

void	ft_send(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
		ft_byte_convert(str[i++], pid);
	ft_byte_convert('\0', pid);
}

int	main(int argc, char **argv)
{
	char	*str;
	int		pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		ft_send(str, pid);
	}
	else
		ft_printf("Usage: ./client <server_pid> <message>");
	return (0);
}
