/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 08:48:23 by pbranco-          #+#    #+#             */
/*   Updated: 2024/09/12 08:48:27 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[i] == '\0')
		return (str);
	else
	{
		while (str[i] != '\0')
		{
			if (str[i] == to_find[j])
			{
				while (str[i + j] == to_find[j] && str[i + j] != '\0')
				{
					j++;
					if (to_find[j] == '\0')
						return (str + i);
				}
				j = 0;
			}
			i++;
		}
	}
	return (0);
}
