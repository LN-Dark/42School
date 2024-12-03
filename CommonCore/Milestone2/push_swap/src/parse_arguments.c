/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:36:44 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/03 15:57:50 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack *create_new_node(int value) {
    t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node) {
        return NULL;
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void add_node_end(t_stack **stack, int value) {
    t_stack *new_node = create_new_node(value);
    t_stack *temp = *stack;

    if (!new_node) {
        return;
    }
    if (!*stack) {
        *stack = new_node;
    } else {
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

t_stack *parse_arguments(int argc, char **argv) {
    t_stack *stack = NULL;
    int i = 1;
    int value;

    while (i < argc) {
        value = atoi(argv[i]);
        add_node_end(&stack, value);
        i++;
    }
    return stack;
}