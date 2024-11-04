/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:17:04 by gude-jes          #+#    #+#             */
/*   Updated: 2024/07/22 09:40:02 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @defgroup bonus Bonus
 * @{
 * @file ft_lstmap.c
 * @brief Iterates the list ’lst’ and applies the function
’f’ on the content of each node. Creates a new
list resulting of the successive applications of
the function ’f’. The ’del’ function is used to
delete the content of a node if needed.
*/

#include "libft.h"

/**
 * @brief Iterates the list and applies the 'f' function. Uses 'del' if needed
 * 
 * @param lst List
 * @param f Function to apply on content of each node
 * @param del Delete content of node if needed
 * @return t_list* new list
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*first;
	t_list	*new;
	void	*set;

	if (!f || !del || !lst)
		return (NULL);
	first = NULL;
	new = NULL;
	while (lst)
	{
		set = f(lst->content);
		new = ft_lstnew(set);
		if (!new)
		{
			del(set);
			ft_lstclear(&first, (*del));
			return (first);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}

/**@}*/