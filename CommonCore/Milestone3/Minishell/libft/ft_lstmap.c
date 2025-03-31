/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_lstmap.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: pbranco- <pbranco-@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/04 10:42:20 by pbranco-		  #+#	#+#			 */
/*   Updated: 2024/11/14 11:27:38 by pbranco-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */
#include "libft.h"

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
