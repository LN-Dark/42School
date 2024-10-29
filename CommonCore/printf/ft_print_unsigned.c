/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:48:03 by pbranco-          #+#    #+#             */
/*   Updated: 2024/10/29 12:52:14 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	int	lenght;
	char *nb;

	lenght = 0;
	if (n == 0)
	{
		lenght = ft_printc('0');
	}
	else
	{
		nb = ft_uitoa(n);
		lenght = ft_printstr(nb);
		free(nb);
	}
	return (lenght);
}