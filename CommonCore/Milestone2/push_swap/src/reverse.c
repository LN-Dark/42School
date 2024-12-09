/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:11:18 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/09 14:37:09 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void rra_rrb(int *arr, int size)
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

void rrr(int *a, int size_a, int *b, int size_b)
{
    rra_rrb(a, size_a);
    rra_rrb(b, size_b);
}