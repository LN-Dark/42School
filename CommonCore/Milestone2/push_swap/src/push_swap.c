/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:36:16 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/03 16:12:58 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack *find_smallest(t_stack *stack) {
    t_stack *smallest = stack;
    while (stack) {
        if (stack->value < smallest->value) {
            smallest = stack;
        }
        stack = stack->next;
    }
    return smallest;
}

void push_all_to_b(t_stack **a, t_stack **b) {
    while (*a) {
        push(a, b);
    }
}

void push_all_to_a(t_stack **a, t_stack **b) {
    while (*b) {
        push(b, a);
    }
}

void push_swap(t_stack *a, t_stack **b) {
    t_stack *smallest;

    while (a && a->next) {
        smallest = find_smallest(a);
        while (a != smallest) {
            rotate(&a);
        }
        push(&a, b);
    }
    push_all_to_a(&a, b);
}