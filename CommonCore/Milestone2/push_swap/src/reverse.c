/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:11:18 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/11 08:56:22 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(struct s_node **head)
{
	struct s_node	*temp;
	struct s_node	*prev;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = *head;
	prev = NULL;
	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL;
	temp->next = *head;
	*head = temp;
}

void	rrb(struct s_node **head)
{
	struct s_node	*temp;
	struct s_node	*prev;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = *head;
	prev = NULL;
	while (temp->next != NULL)
	{
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL;
	temp->next = *head;
	*head = temp;
}

void	rrr(struct s_node **stack_a, struct s_node **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
