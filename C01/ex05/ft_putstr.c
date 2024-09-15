/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 08:51:51 by pbranco-          #+#    #+#             */
/*   Updated: 2024/09/06 08:51:53 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;
	int	tamanho;

	i = 0;
	tamanho = sizeof(str) / sizeof(*str);
	while (i < tamanho)
	{
		write(1, &str[i], 1);
		i++;
	}
}
