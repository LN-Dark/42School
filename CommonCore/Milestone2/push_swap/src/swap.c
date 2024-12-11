/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:10:29 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/11 08:57:48 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(struct s_node **head)
{
	struct s_node	*first;
	struct s_node	*second;

	if (*head != NULL && (*head)->next != NULL)
	{
		first = *head;
		second = (*head)->next;
		first->next = second->next;
		second->next = first;
		*head = second;
	}
}

void	sb(struct s_node **head)
{
	struct s_node	*first;
	struct s_node	*second;

	if (*head != NULL && (*head)->next != NULL)
	{
		first = *head;
		second = (*head)->next;
		first->next = second->next;
		second->next = first;
		*head = second;
	}
}

void	ss(struct s_node **stack_a, struct s_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
