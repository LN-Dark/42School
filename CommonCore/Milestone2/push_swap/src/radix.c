/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:06:04 by pbranco-          #+#    #+#             */
/*   Updated: 2024/12/13 16:02:55 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	bitwise_sort(t_stlist **stack_a, t_stlist **stack_b, int i)
{
	int			j;
	int			size;
	t_stlist	*temp;

	size = stack_size(*stack_a);
	j = 0;
	while (j++ < size)
	{
		temp = *stack_a;
		if ((temp->index >> i) & 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
	}
}

void	radix_sort(t_stlist **stack_a, t_stlist **stack_b)
{
	int	i;

	i = 0;
	while (is_sorted(*stack_a) != 1 && i < 32)
	{
		bitwise_sort(stack_a, stack_b, i);
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
	free_stack(stack_b);
}

int	ft_is_repeated(t_stlist	*stack_a, int nb)
{
	while (stack_a)
	{
		if (stack_a->value == nb)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int	process_input_method_0(int argc, char **argv, t_stlist **stack_a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigitplussign(argv[i][j]))
				j++;
			else
				return (1);
		}
		if (ft_is_repeated(*stack_a, ft_atol(argv[i])) != 1)
			if (ft_atol(argv[i]) >= -2147483648 && ft_atol(argv[i]) <= 2147483647)
				push(stack_a, ft_atoi(argv[i]));
			else
				return (1);
		else
			return (1);
	}
	return (0);
}

int	process_input_method_1(int argc, char **argv, t_stlist **stack_a)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigitplussign(argv[i][j]))
				j++;
			else
				return (1);
		}
		if (ft_is_repeated(*stack_a, ft_atol(argv[i])) != 1)
			if (ft_atol(argv[i]) >= -2147483648 && ft_atol(argv[i]) <= 2147483647)
				push(stack_a, ft_atoi(argv[i]));
			else
				return (1);
		else
			return (1);
	}
	return (0);
}
