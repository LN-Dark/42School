/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:11:02 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/09 15:38:25 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void ra(int *stack_a, int size_a) {
    if (size_a > 1) {
        int temp = stack_a[size_a - 1];
        for (int i = size_a - 1; i > 0; i--) {
            stack_a[i] = stack_a[i - 1];
        }
        stack_a[0] = temp;
    }
}

void rb(int *stack_b, int size_b) {
    if (size_b > 1) {
        int temp = stack_b[size_b - 1];
        for (int i = size_b - 1; i > 0; i--) {
            stack_b[i] = stack_b[i - 1];
        }
        stack_b[0] = temp;
    }
}

void rr(int *stack_a, int size_a, int *stack_b, int size_b) {
    ra(stack_a, size_a);
    rb(stack_b, size_b);
}

