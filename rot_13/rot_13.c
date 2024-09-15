/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:58:00 by pbranco-          #+#    #+#             */
/*   Updated: 2024/09/15 14:58:01 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	changechar(char *str)
{	
	while (*str != '\0')
	{
		if ((*str >= 'A' && *str <= 'M') || (*str >= 'a' && *str <= 'm'))
			*str += 13;
		else if ((*str >= 'N' && *str <= 'Z') || (*str >= 'n' && *str <= 'z'))
			*str -= 13;
		write(1, str, 1);
		str++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		changechar(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}
