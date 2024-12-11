/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:10:48 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/11 08:57:31 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(struct s_node **stack_a, struct s_node **stack_b)
{
	int	data;

	if (*stack_b != NULL)
	{
		data = pop(stack_b);
		push(stack_a, data);
	}
}

void	pb(struct s_node **stack_a, struct s_node **stack_b)
{
	int	data;

	if (*stack_a != NULL)
	{
		data = pop(stack_a);
		push(stack_b, data);
	}
}
