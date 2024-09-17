/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 14:02:40 by pbranco-          #+#    #+#             */
/*   Updated: 2024/09/15 14:02:41 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_replace(char *str, char a, char b)
{
	int	i;
	
	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] == a)
		{
			str[i] = b;
		}
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int 	main(int argc, char **argv)
{
	if(argc == 4)
	{
		if(ft_strlen(argv[2]) == 1 && ft_strlen(argv[3]) == 1)
		{
			ft_replace(argv[1], argv[2][0], argv[3][0]);	
		}
	}
	write(1, "\n", 1);
	return (0);
}
