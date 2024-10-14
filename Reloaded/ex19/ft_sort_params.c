/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:09:08 by pbranco-          #+#    #+#             */
/*   Updated: 2024/09/18 09:09:09 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(str);
		str++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	pos;

	pos = 0;
	while (s1[pos] != '\0' || s2[pos] != '\0')
	{
		if (s1[pos] == s2[pos])
		{
			pos++;
		}
		if (s1[pos] < s2 [pos] || s1[pos] > s2 [pos])
		{
			return (s1[pos] - s2[pos]);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) > 0)
			{
				temp = argv[i];
				argv[i] = argv[j];
				argv[j] = temp;
			}
		}
	}
	i = 0;
	while (++i < argc)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
	}
	return (0);
}
