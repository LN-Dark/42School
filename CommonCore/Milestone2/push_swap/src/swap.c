/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:46:38 by pbranco-          #+#    #+#             */
/*   Updated: 2024/12/13 10:15:31 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stlist **head)
{
	t_stlist	*first;
	t_stlist	*second;
	if (*head != NULL && (*head)->next != NULL)
	{
		first = *head;
		second = (*head)->next;
		first->next = second->next;
		second->next = first;
		*head = second;
	}
	ft_printf("sa\n");
}