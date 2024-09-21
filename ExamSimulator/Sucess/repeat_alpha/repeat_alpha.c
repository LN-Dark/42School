/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 08:55:44 by pbranco-          #+#    #+#             */
/*   Updated: 2024/09/20 08:55:45 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void alpha(char *str)
{
	char up[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char down[] = "abcdefghijklmnopqrstuvwxyz";
	int i = 0;
	int j = 0;
	int h = 0;
	while(str[i] != '\0')
	{
		if(str[i] >= 'A' && str[i] <= 'Z')
		{
			while(j <= 25)
			{
				if(str[i] == up[j])
				{
					while(h <= j)
					{
						write(1, &str[i], 1);
						h++;
					}
					h = 0;
					break;
				}
				j++;
			}
			j = 0; 
		}
		else if(str[i] >= 'a' && str[i] <= 'z')
		{
			while(j <= 25)
			{
				if(str[i] == down[j])
				{
					while(h <= j)
					{
						write(1, &str[i], 1);
						h++;
					}
					h = 0;
					break;
				}
				j++;
			}
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
