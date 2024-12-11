/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:11:02 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/11 09:56:26 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_list **head)
{
	t_list	*temp;
	t_list	*first;

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

void	rb(t_list **head)
{
	t_list	*temp;
	t_list	*first;

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

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}