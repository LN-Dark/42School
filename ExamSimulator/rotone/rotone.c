/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 13:39:12 by pbranco-          #+#    #+#             */
/*   Updated: 2024/09/16 13:39:12 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void rotone(char *str)
{
	int i;
	char c;
	
	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			if(str[i] == 'Z')
			{
				write(1, "A", 1);
			}else
			{
				c = str[i] + 1;
				write(1, &c, 1);
			}
		}else if(str[i] >= 'a' && str[i] <= 'z')
		{
			if(str[i] == 'z')
			{
				
				write(1, "a", 1);
			}else
			{
				c = str[i] + 1;
				write(1, &c, 1);
			}
		}else
		{
			c = str[i];
			write(1, &c, 1);
		}
		
		i++;
	}
}

int main(int argc, char **argv)
{
	if(argc == 2)
		rotone(argv[1]);
	write(1, "\n", 1);	
	return(0);
}

