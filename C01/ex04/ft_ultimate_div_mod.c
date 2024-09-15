/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 08:45:45 by pbranco-          #+#    #+#             */
/*   Updated: 2024/09/06 08:45:48 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	resulta;
	int	resultb;

	resulta = *a / *b;
	resultb = *a % *b;
	*a = resulta;
	*b = resultb;
}
