/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:10:48 by pbranco-          #+#    #+#             */
/*   Updated: 2024/12/12 14:18:49 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	process_input(int argc, char **argv, t_stlist **stack_a, int method)
{
	if (method == 0)
		return (process_input_method_0(argc, argv, stack_a));
	else
		return (process_input_method_1(argc, argv, stack_a));
}

void	sort_and_cleanup(t_stlist **stack_a, t_stlist **stack_b)
{
	assign_indices(*stack_a);
	radix_sort(stack_a, stack_b);
	free_stack(stack_a);
}

int	main(int argc, char **argv)
{
	t_stlist	*stack_a;
	t_stlist	*stack_b;
	char		**str;
	int			i;

	str = NULL;
	if (argc == 2)
		str = ft_split(argv[1], ' ');
	else if (argc == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (str != NULL)
	{
		i = 0;
		while (str[i])
			i++;
		if (process_input(i, str, &stack_a, 1) == 1)
			return (ft_printf("Error\n"), 0);
	}
	else
		if (process_input(argc, argv, &stack_a, 0) == 1)
			return (ft_printf("Error\n"), 0);
	sort_and_cleanup(&stack_a, &stack_b);
	return (0);
}
