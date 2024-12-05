/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:11:18 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/05 10:43:31 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void rotate_top_to_bottom(int *arr, int size)
{
	int last;
	int i;

    if (size < 2)
    {
        return;
    }

    last = arr[size - 1];
    i = size - 1;
    while (i > 0)
    {
        arr[i] = arr[i - 1];
        i--;
    }
    arr[0] = last;
}

void rotate_both_top_to_bottom(int *a, int size_a, int *b, int size_b)
{
    rotate_top_to_bottom(a, size_a);
    rotate_top_to_bottom(b, size_b);
}