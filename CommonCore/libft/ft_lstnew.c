/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:17:06 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/22 10:53:23 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file ft_lstnew.c
 * @brief Allocates (with malloc(3)) and returns a new node.
The member variable ’content’ is initialized with
the value of the parameter ’content’. The variable
’next’ is initialized to NULL.
*/

#include "libft.h"

/**
 * @brief Creates a new node
 * 
 * @param content Content of node
 * @return t_list* List
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc (sizeof(*lst));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

/**@}*/