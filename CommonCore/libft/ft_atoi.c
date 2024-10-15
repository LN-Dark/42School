/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:00:00 by pbranco-          #+#    #+#             */
/*   Updated: 2024/10/15 09:00:03 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

int	ft_atoi(const char *str)
{
	int i;
	int signal;
	int result;
	
	i = 0;
	signal = 1;
	result = 0;

	while (str[i] < 33 && str[i] != 127 && str[i] != '\0')
		i++;
	if ((str[i] == 43 || str[i] == 45) && (str[i + 1] == 43
		|| str[i + 1] == 45) && str[i] != '\0')
	{
		return (0);
	}
	else
	{
		if(str[i] == 45)
			signal *= -1;
	}
	i++;
	while (str[i] >= 48 && str[i] <= 57 && str[i] != '\0')
	{
		result *= 10;
		result += str[i] - 48;
		i++; 
	}
	result *= signal;
	return (result);
}
