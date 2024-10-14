/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:08:22 by pbranco-          #+#    #+#             */
/*   Updated: 2024/09/16 11:08:23 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	ind;
	long	count;

	count = nb;
	if (count <= 0)
		return (0);
	if (count == 1)
		return (1);
	ind = 2;
	if (count >= 2)
	{
		while (ind * ind <= count)
		{
			if (ind * ind == count)
				return (ind);
			ind++;
		}
	}
	return (0);
}
