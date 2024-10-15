/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:11:46 by pbranco-          #+#    #+#             */
/*   Updated: 2024/10/15 10:11:46 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <libft.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t i;
	int i;
	
	i = 0;
	if (size == 0) {
		return ft_strlen(src);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return ft_strlen(src);
}
