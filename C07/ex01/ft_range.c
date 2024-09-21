/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 08:20:28 by pbranco-          #+#    #+#             */
/*   Updated: 2024/09/21 08:20:29 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*matrix;
	int	i;
	int	size;

	i = 0;
	size = max - min;
	if (min >= max)
		return (NULL);
	matrix = malloc(sizeof(int) * size);
	if (!matrix)
		return (NULL);
	while (i <= size)
	{
		matrix[i] = min;
		i++;
		min++;
	}
	return (matrix);
}
