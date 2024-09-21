/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:29:42 by pbranco-          #+#    #+#             */
/*   Updated: 2024/09/21 11:29:43 by pbranco-         ###   ########.fr       */
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
	return(i);
}

void inter(char *str1, char *str2)
{
	int i = 0;
	int j = 1;

	while(str1[i] != '\0')
	{
		j = i + 1;
		while(str1[j] != '\0' && ft_strlen(str1) >= j){
			if(str1[j] == str1[i])
			{
				str1[j] = 35;
			}
			j++;
		}	
		i++;
	}
	i = 0;
	j = 0;
	while(str1[i] != '\0')
	{
		while(str2[j] != '\0'){
			if(str2[j] == str1[i] && j >= i && str1[i] != 35)
			{
				write(1, &str1[i], 1);
				break;
			}
			j++;
		}
		j = 0;	
		i++;
	}

}

int main(int argc, char **argv)
{
	if(argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return(0);
}
