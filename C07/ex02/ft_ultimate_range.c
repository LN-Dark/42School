/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 08:20:59 by pbranco-          #+#    #+#             */
/*   Updated: 2024/09/21 08:21:00 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*matrix;
	int	i;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	matrix = malloc(sizeof(int) * (max - min));
	if (!matrix)
		return (-1);
	while (min < max)
	{
		matrix[i] = min;
		i++;
		min++;
	}
	*range = matrix;
	return (i);
}
