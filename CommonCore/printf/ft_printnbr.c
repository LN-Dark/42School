/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:11:19 by pbranco-          #+#    #+#             */
/*   Updated: 2024/10/29 11:13:12 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printnbr(int nb)
{
	int		lenght;
	char	*nbstr;

	lenght = 0;
	nbstr = ft_itoa(nb);
	lenght = ft_printstr(nbstr);
	free(nbstr);
	return (lenght);
}