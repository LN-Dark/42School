/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:16:48 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/22 10:53:40 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file ft_lstadd_front.c
 * @brief Adds the node ’new’ at the beginning of the list.
*/

#include "libft.h"

/**
 * @brief Adds a new node to the start of the list
 * 
 * @param lst List
 * @param new New Node
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}

/**@}*/