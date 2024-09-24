/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:06:49 by pbranco-          #+#    #+#             */
/*   Updated: 2024/09/24 14:06:50 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
# include <stdlib.h>

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return(i);
}

void unionv(char *str, char *str2)
{
	int i = 0;
	int j = 0;

	while(str[i] != '\0')
	{
		j = 0;
		while(str[j] != '\0')
		{
			if(str[i] == str[j] && i != j)
			{
				str[j] = 35;
			}
			j++;
		}
		i++;
	}
	i = 0;
	j = 0;
	while(str2[i] != '\0')
	{
		j = 0;
		while(str2[j] != '\0')
		{
			if(str2[i] == str2[j] && i != j)
			{
				str2[j] = 35;
			}
			j++;
		}
		i++;
	}
	
	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] != 35)
		{
			write(1, &str[i], 1);
		}
		i++;
	}
	
	
	
	
	
	i = 0;
	j = 0;
	while(str2[i] != '\0')
	{
		j = 0;
		while(str[j] != '\0')
		{
			if(str2[i] == str[j])
			{
				str2[i] = 35;
				break;
			}
			j++;
		}
		i++;
	}
	
	i = 0;
	while(str2[i] != '\0')
	{
		if(str2[i] != 35)
		{
			write(1, &str2[i], 1);
		}
		i++;
	}
		
}

int main(int argc, char **argv)
{
	if(argc == 3)
		unionv(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
