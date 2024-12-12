/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:10:48 by pbranco-          #+#    #+#             */
/*   Updated: 2024/12/12 08:52:51 by pbranco-         ###   ########.fr       */
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
    int i;
    int j;
    int size;
    t_stlist *temp;

    i = 0;
    size = stack_size(*stack_a);
    while (i < 32 && ft_check_sort(*stack_a))
    {
        j = 0;
        while (j++ < size)
        {
            temp = *stack_a;
            if ((temp->index >> i) & 1){
                ra(stack_a);
                ft_printf("ra\n");
            }
            else{
                pb(stack_a, stack_b);
                ft_printf("pb\n");
            }
        }
        while (*stack_b){
            pa(stack_a, stack_b);
            ft_printf("pa\n");
        }
        i++;
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
    free_stack(&stack_a);
    return (0);
}