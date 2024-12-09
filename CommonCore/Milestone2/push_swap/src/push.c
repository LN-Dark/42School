/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:10:48 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/09 15:38:29 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void pa(int *stack_a, int *size_a, int *stack_b, int *size_b) {
    if (*size_b > 0) {
        stack_a[*size_a] = stack_b[*size_b - 1];
        (*size_a)++;
        (*size_b)--;
    }
}

void pb(int *stack_a, int *size_a, int *stack_b, int *size_b) {
    if (*size_a > 0) {
        stack_b[*size_b] = stack_a[*size_a - 1];
        (*size_b)++;
        (*size_a)--;
    }
}

