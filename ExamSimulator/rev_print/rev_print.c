/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:25:40 by pbranco-          #+#    #+#             */
/*   Updated: 2024/09/20 13:25:41 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void rev(char *str)
{
	int i = ft_strlen(str) - 1;
	while(i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
	
}

int main(int argc, char **argv)
{
	if(argc == 2)
		rev(argv[1]);
	write(1, "\n", 1);
	return(0);
}