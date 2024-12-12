/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:10:48 by pbranco-          #+#    #+#             */
/*   Updated: 2024/12/12 11:40:09 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	is_sorted(t_stlist *head)
{
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

void	assign_indices(t_stlist *stack)
{
	t_stlist	*current;
	t_stlist	*compare;
	int			index;

	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (current->value > compare->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

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
		{
			ra(stack_a);
			ft_printf("ra\n");
		}
		else
		{
			pb(stack_a, stack_b);
			ft_printf("pb\n");
		}
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
		{
			pa(stack_a, stack_b);
			ft_printf("pa\n");
		}
		i++;
	}
	free_stack(stack_b);
}

int	ft_is_repeated(t_stlist	*stack_a, int nb)
{
	while (stack_a)
	{
		if(stack_a->value == nb)
			return(1);
		stack_a = stack_a->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stlist	*stack_a;
	t_stlist	*stack_b;
	int			i;

	if (argc < 2)
		return (1);
	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	while (i < argc)
	{
		if (ft_is_repeated(stack_a, ft_atoi(argv[i])) != 1)
			push(&stack_a, ft_atoi(argv[i]));
		else
		{
			ft_printf("ERROR\n");
			return (0);
		}
		
		i++;
	}
	assign_indices(stack_a);
	radix_sort(&stack_a, &stack_b);

	free_stack(&stack_a);
	return (0);
}
