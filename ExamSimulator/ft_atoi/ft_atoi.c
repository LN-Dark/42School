/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:56:00 by pbranco-          #+#    #+#             */
/*   Updated: 2024/09/19 09:56:01 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int i = 0;
	int j = 0;
	int signal = 1;
	while(str[i] != '\0')
	{
		if(str[i] >= 43 && str[i] <= 57 && (str[i] != 44 && str[i] != 46 && str[i] != 47) )
		{
			if(str[i] == 45 || str[i] == 43)
			{
				if (str[i] == 45)
					signal *= -1;
			}
			else
			{
				j *= 10;
				j += str[i] - 48;
			}
			if (!(str[i + 1] >= 48 && str[i + 1] <=57))
				break;
		}
		i++;
	}
	j = j* signal;
	return(j);
}
/*
int main(void){
	printf("%d\n%d\n", ft_atoi("-12345+TRAA"), atoi("-12345+TRAA"));
}
*/
