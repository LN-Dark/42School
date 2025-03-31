/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:02:35 by pcruz             #+#    #+#             */
/*   Updated: 2025/02/07 12:17:21 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*allocate_word(char *str, int start, int end)
{
	char	*word;

	word = (char *)ft_calloc(end - start + 1, sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, str + start, end - start + 1);
	return (word);
}
