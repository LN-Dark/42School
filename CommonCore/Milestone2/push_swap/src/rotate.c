/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:11:02 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/05 10:43:46 by pcruz            ###   ########.fr       */
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
    rotate_array(a, size_a);
    rotate_array(b, size_b);
}

