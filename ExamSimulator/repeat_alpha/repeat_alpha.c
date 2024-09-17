/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 08:52:08 by pbranco-          #+#    #+#             */
/*   Updated: 2024/09/17 08:52:09 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void alpha(char *str)
{
	int i;
	int j;
	int h;
	char upalpha[26] = {'A','B','C','D','E','F','G','H','I','J','K', 'L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char downalpha[26] = {'a','b','c','d','e','f','g','h','i','j','k', 'l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	
	i = 0;
	j = 0;
	h = 0;
	while(str[i] != '\0')
	{
		if(str[i] >= 'a' && str[i] <= 'z')
		{
			while(downalpha[j] != str[i])
			{
				j++;
			}
			while(h <= (j))
			{
				write(1, &str[i], 1);
				h++;
			}
			h = 0;
			j = 0;
		}
		else if(str[i] >= 'A' && str[i] <= 'Z')
		{
			while(upalpha[j] != str[i])
			{
				j++;
			}
			while(h <= (j))
			{
				write(1, &str[i], 1);
				h++;
			}
			h = 0;
			j = 0;
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
		alpha(argv[1]);
	write(1, "\n", 1);
	return (0);
}
