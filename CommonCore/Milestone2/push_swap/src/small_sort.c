/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:41:12 by pbranco-          #+#    #+#             */
/*   Updated: 2024/12/13 10:51:37 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sort_two(t_stlist **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

void	sort_three(t_stlist **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > c && b < c)
		ra(stack_a);
	else if (b > a && a > c)
		rra(stack_a);
	else if (b > c && c > a)
    {
		sa(stack_a);
		ra(stack_a);
	}
	else if (c > a && c > b)
		sa(stack_a);
}
void	find_and_move_min(t_stlist **stack_a)
{
	int			min;
	t_stlist	*temp;
    
	min = (*stack_a)->value;
	temp = *stack_a;
	while (temp)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	while ((*stack_a)->value != min)
		ra(stack_a);
}

void	sort_four(t_stlist **stack_a, t_stlist **stack_b)
{
	int	count;
    
	count = 5;
	while (--count > 0)
	{
		find_and_move_min(stack_a);
		pb(stack_a, stack_b);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	sort_five(t_stlist **stack_a, t_stlist **stack_b)
{
	int	count;

	count = 6;
	while (--count > 1)
	{
		find_and_move_min(stack_a);
		pb(stack_a, stack_b);
	}
	sort_four(stack_a, stack_b);
	while (*stack_b)
		pa(stack_a, stack_b);
}