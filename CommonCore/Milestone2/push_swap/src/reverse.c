/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:11:18 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/11 11:11:28 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_stlist **head)
{
	t_stlist	*temp;
	t_stlist	*prev;

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

void	rrb(t_stlist **head)
{
	t_stlist	*temp;
	t_stlist	*prev;

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

void	rrr(t_stlist **stack_a, t_stlist **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
