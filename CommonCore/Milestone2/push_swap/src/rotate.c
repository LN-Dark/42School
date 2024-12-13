/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:11:02 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/12 11:50:32 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stlist **head)
{
	t_stlist	*temp;
	t_stlist	*first;

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
