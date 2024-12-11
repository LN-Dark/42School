/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:57:22 by pbranco-          #+#    #+#             */
/*   Updated: 2024/12/11 09:59:56 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	pop(t_list **head)
{
	t_list	*temp;
	int		popped_data;

	if (*head == NULL)
		return (-1);
	temp = *head;
	popped_data = temp->value;
	*head = (*head)->next;
	free(temp);
	return (popped_data);
}

void	push(t_list **head, int new_data)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	new_node->value = new_data;
	new_node->next = *head;
	*head = new_node;
}

int	stack_size(t_list *head)
{
	int	size;

	size = 0;
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}

void	free_stack(t_list **head)
{
	t_list	*temp;

	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}
