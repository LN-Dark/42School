/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:10:48 by pbranco-          #+#    #+#             */
/*   Updated: 2024/12/11 11:32:32 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void assign_indices(t_stlist *stack)
{
    t_stlist *current;
    t_stlist *compare;
    int index;

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

void radix_sort(t_stlist **stack_a, t_stlist **stack_b)
{
    int max_num, max_bits, i, j, size;
    t_stlist *current;

    size = stack_size(*stack_a);
    max_num = size - 1;
    max_bits = 0;
    while ((max_num >> max_bits) != 0)
        max_bits++;

    for (i = 0; i < max_bits; i++)
    {
        for (j = 0; j < size; j++)
        {
            current = *stack_a;
            if (((current->index >> i) & 1) == 1){
                ra(stack_a);
                ft_printf("ra\n");
            }
            else{
                pb(stack_a, stack_b);
                ft_printf("pb\n");
            }
        }
        while (stack_size(*stack_b) != 0){
            pa(stack_a, stack_b);
            ft_printf("pa\n");
        }
    }
}

int main(int argc, char **argv)
{
    t_stlist *stack_a = NULL;
    t_stlist *stack_b = NULL;
    int i;

    if (argc < 2)
        return (1);
    for (i = 1; i < argc; i++)
        push(&stack_a, ft_atoi(argv[i]));

    assign_indices(stack_a);
    radix_sort(&stack_a, &stack_b);

    // Print the sorted stack
    while (stack_a)
    {
        printf("%d\n", stack_a->value);
        stack_a = stack_a->next;
    }

    free_stack(&stack_a);
    return (0);
}