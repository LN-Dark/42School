/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:04:28 by pbranco-          #+#    #+#             */
/*   Updated: 2024/10/29 11:05:24 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_put_hex(unsigned long nb, const char form)
{
	char	base_m;
	char	base;
	int		result;

	result = 0;
	base = "0123456789abcdef";
	base_m = "0123456789ABCDEF";
	
		if (nb >= 16)
		{
			result += ft_put_hex(nb / 16, form);
			result += ft_put_hex(nb % 16, form);
		}
		else
		{
			if (form == 'x')
				ft_putchar_fd(base[nb]);
			else
				ft_putchar_fd(base_m[nb]);
		}
		return (count);
}