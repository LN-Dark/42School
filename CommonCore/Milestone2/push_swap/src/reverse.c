/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:11:18 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/09 15:38:27 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void rra(int *stack_a, int size_a) {
    if (size_a > 1) {
        int temp = stack_a[0];
        for (int i = 0; i < size_a - 1; i++) {
            stack_a[i] = stack_a[i + 1];
        }
        stack_a[size_a - 1] = temp;
    }
}

void rrb(int *stack_b, int size_b) {
    if (size_b > 1) {
        int temp = stack_b[0];
        for (int i = 0; i < size_b - 1; i++) {
            stack_b[i] = stack_b[i + 1];
        }
        stack_b[size_b - 1] = temp;
    }
}

void rrr(int *stack_a, int size_a, int *stack_b, int size_b) {
    rra(stack_a, size_a);
    rrb(stack_b, size_b);
}