/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:41:12 by pbranco-          #+#    #+#             */
/*   Updated: 2024/12/18 11:38:09 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_two(t_stlist **stack_a)
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
	if (a > b && b > c && !is_sorted(*stack_a))
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > c && b < c && !is_sorted(*stack_a))
		ra(stack_a);
	else if (b > a && a > c && !is_sorted(*stack_a))
		rra(stack_a);
	else if (b > c && c > a && !is_sorted(*stack_a))
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (c > a && c > b && !is_sorted(*stack_a))
		sa(stack_a);
}

void	find_and_move_min(t_stlist **stack_a)
{
	int			min;
	int			rracheck;
	t_stlist	*temp;

	if (*stack_a == NULL)
		return ;
	rracheck = 0;
	min = (*stack_a)->value;
	temp = *stack_a;
	while (temp)
	{
		if (temp->value < min)
			min = temp->value;
		temp = temp->next;
	}
	if (is_reverse_sorted(*stack_a))
	{
		rracheck = 1;
		rra(stack_a);
	}
	while ((*stack_a) && (*stack_a)->value != min && rracheck == 0)
		ra(stack_a);
}

void	sort_four(t_stlist **stack_a, t_stlist **stack_b)
{
	if (!is_sorted(*stack_a))
	{
		find_and_move_min(stack_a);
		pb(stack_a, stack_b);
		sort_three(stack_a);
		pa(stack_a, stack_b);
	}
}

void	sort_five(t_stlist **stack_a, t_stlist **stack_b)
{
	if (!is_sorted(*stack_a))
	{
		find_and_move_min(stack_a);
		pb(stack_a, stack_b);
		sort_four(stack_a, stack_b);
		pa(stack_a, stack_b);
	}
}
