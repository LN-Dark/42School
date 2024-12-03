/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:28:09 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/03 16:12:37 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        return 1;
    }
    t_stack *a = parse_arguments(argc, argv);
    t_stack *b = NULL;
    if (!a) {
        ft_printf("Error\n");
        return 1;
    }
    ft_printf("Stack A:\n");
    print_stack(a);
    push_swap(a, &b);
    ft_printf("Stack B:\n");
    print_stack(b);
    free_stack(a);
    free_stack(b);

    return 0;
}

void print_stack(t_stack *stack) {
    while (stack) {
        printf("%d\n", stack->value);
        stack = stack->next;
    }
}