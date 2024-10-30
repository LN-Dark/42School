/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:17:21 by pbranco-          #+#    #+#             */
/*   Updated: 2024/09/05 13:43:25 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_is_negative(int n)
{
	char	positive_negative;

	if (n < 0)
	{
		positive_negative = 'N';
		ft_putchar(positive_negative);
	}
	else
	{
		positive_negative = 'P';
		ft_putchar(positive_negative);
	}
}
