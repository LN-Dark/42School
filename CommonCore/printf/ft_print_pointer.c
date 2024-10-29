/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:01:05 by pbranco-          #+#    #+#             */
/*   Updated: 2024/10/29 11:07:21 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_ptr(unsigned long pointer)
{
	int	lenght;

	lenght = 0;
	if (!pointer)
	{
		lenght = ft_putstr_fd("(null)", 1);
		return(6);
	}
	else
	{
		lenght += ft_printstr("0x");
		lenght += ft_put_hex(pointer, 'x');
	}
	return (lenght);
}