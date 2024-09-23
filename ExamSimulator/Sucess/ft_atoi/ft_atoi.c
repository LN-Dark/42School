/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:31:56 by pbranco-          #+#    #+#             */
/*   Updated: 2024/09/23 18:31:58 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{

	int i = 0;
	int signal = 1;
	int count = 0;
	
	while(str[i] != 0 &&  str[i] <= 32)
	{
		i++;
	}
	while(str[i] >= 43 && str[i] < 48 && str[i] != 44 && str[i] != 46 && str[i] != 47)
	{
		if(str[i] == 45)
			signal *= -1;
		i++;
	}
	while(str[i] >= 48 && str[i] <= 57)
	{
		count *= 10;
		count += str[i] - 48;
		i++;
	}
	count *= signal;
	return (count);
}
/*
int main(void){
	printf("%d\n%d\n", ft_atoi("-12345+TRAA"), atoi("-12345+TRAA"));
}
*/
