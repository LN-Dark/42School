/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:44:14 by pbranco-          #+#    #+#             */
/*   Updated: 2024/12/13 10:15:38 by pbranco-         ###   ########.fr       */
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
	ft_printf("rra\n");
}
