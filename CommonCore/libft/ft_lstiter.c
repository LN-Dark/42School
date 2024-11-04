/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:16:54 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/22 10:55:06 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file ft_lstiter.c
 * @brief Iterates the list ’lst’ and applies the function
’f’ on the content of each node.
*/

#include "libft.h"

/**
 * @brief Iterate a list and apply f function
 * 
 * @param lst List
 * @param f Function to apply on each node
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/**@}*/