/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:11:02 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/05 11:07:48 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void shift_bottom_to_top(int *arr, int size)
{
	int i;
	int last;

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

void rotate_both(int *a, int size_a, int *b, int size_b)
{
    shift_bottom_to_top(a, size_a);
    shift_bottom_to_top(b, size_b);
}

