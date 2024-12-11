/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:10:29 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/11 11:11:39 by pbranco-         ###   ########.fr       */
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
}

void	sb(t_stlist **head)
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
}

void	ss(t_stlist **stack_a, t_stlist **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
