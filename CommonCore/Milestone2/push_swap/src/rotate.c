/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:11:02 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/11 08:56:33 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(struct s_node **head)
{
	struct s_node	*temp;
	struct s_node	*first;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = *head;
	first = *head;
	while (temp->next != NULL)
		temp = temp->next;
	*head = first->next;
	first->next = NULL;
	temp->next = first;
}

void	rb(struct s_node **head)
{
	struct s_node	*temp;
	struct s_node	*first;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp = *head;
	first = *head;
	while (temp->next != NULL)
		temp = temp->next;
	*head = first->next;
	first->next = NULL;
	temp->next = first;
}

void	rr(struct s_node **stack_a, struct s_node **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}
