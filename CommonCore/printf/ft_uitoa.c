/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:46:07 by pbranco-          #+#    #+#             */
/*   Updated: 2024/10/29 12:47:05 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static unsigned int	ft_nb_size(int nb)
{
	unsigned int	length;

	length = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		length++;
	while (nb != 0)
	{
		nb /= 10;
		length++;
	}
	return (length);
}

char	*ft_uitoa(unsigned int n)
{
	unsigned int	length;
	char			*string;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	length = ft_nb_size(n);
	string = (char *)malloc(sizeof(char) * (length + 1));
	if (string == NULL)
		return (NULL);
	if (n < 0)
	{
		string[0] = '-';
		n = -n;
	}
	if (n == 0)
		string[0] = '0';
	string[length] = '\0';
	while (n != 0)
	{
		string[length - 1] = (n % 10) + '0';
		n = n / 10;
		length--;
	}
	return (string);
}