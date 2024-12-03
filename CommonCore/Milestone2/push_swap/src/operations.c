/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:37:10 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/03 16:03:13 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void push(t_stack **src, t_stack **dest) {
    t_stack *temp;

    if (!src || !*src) {
        return;
    }
    temp = *src;
    *src = (*src)->next;
    temp->next = *dest;
    *dest = temp;
}

void swap(t_stack *stack) {
    int temp;

    if (!stack || !stack->next) {
        return;
    }
    temp = stack->value;
    stack->value = stack->next->value;
    stack->next->value = temp;
}

void rotate(t_stack **stack) {
    t_stack *temp;
    t_stack *last;

    if (!stack || !*stack || !(*stack)->next) {
        return;
    }
    temp = *stack;
    *stack = (*stack)->next;
    temp->next = NULL;

    last = *stack;
    while (last->next) {
        last = last->next;
    }
    last->next = temp;
}

void reverse_rotate(t_stack **stack) {
    t_stack *temp;
    t_stack *prev;

    if (!stack || !*stack || !(*stack)->next) {
        return;
    }
    temp = *stack;
    while (temp->next) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    temp->next = *stack;
    *stack = temp;
}

void free_stack(t_stack *stack) {
    t_stack *temp;

    while (stack) {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}