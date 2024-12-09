/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:10:29 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/09 15:38:23 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/push_swap.h"

void sa(int *stack_a, int size_a) {
    if (size_a > 1) {
        int temp = stack_a[size_a - 1];
        stack_a[size_a - 1] = stack_a[size_a - 2];
        stack_a[size_a - 2] = temp;
    }
}

void sb(int *stack_b, int size_b) {
    if (size_b > 1) {
        int temp = stack_b[size_b - 1];
        stack_b[size_b - 1] = stack_b[size_b - 2];
        stack_b[size_b - 2] = temp;
    }
}

void ss(int *stack_a, int size_a, int *stack_b, int size_b) {
    sa(stack_a, size_a);
    sb(stack_b, size_b);
}