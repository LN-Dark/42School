/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:41:08 by pbranco-          #+#    #+#             */
/*   Updated: 2024/09/24 16:41:09 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return(i);
}

char    *ft_strrev(char *str)
{
	char *str2;
	int i = 0;
	int j = ft_strlen(str) - 1;

	str2 = malloc((sizeof(char)) * ft_strlen(str) + 1);
	if(ft_strlen(str) == 0)
	{
		return(str);
	}
	while(str[i] != '\0')
	{
		str2[i] = str[j];
		i++;
		j--;
	}
	str2[i] = '\0';
	i = 0;
	while(str[i] != '\0')
	{
		str[i] = str2[i];
		i++;
	}
	str[i] = '\0';
	free(str2);
	return(str);
}
