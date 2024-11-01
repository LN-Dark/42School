/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:15:40 by pbranco-          #+#    #+#             */
/*   Updated: 2024/09/18 14:15:41 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void rot(char *str)
{
	int i = 0;
	char c;
	while(str[i] != '\0')
	{
		if((str[i] >= 'A' && str[i] <= 'M') || (str[i] >= 'a' && str[i] <= 'm'))
		{
			c = str[i] + 13;
			write(1, &c, 1);
		}
		else if((str[i] > 'M' && str[i] <= 'Z') || (str[i] > 'm' && str[i] <= 'z'))
		{
			c = str[i] - 13;
			write(1, &c, 1);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if(argc == 2)
		rot(argv[1]);
	write(1, "\n", 1);
	return (0);
}
