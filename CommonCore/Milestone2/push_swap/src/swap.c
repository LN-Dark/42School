/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:10:29 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/05 10:44:23 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/push_swap.h"

void swap_first_two(int arr[], int size)
{
	int temp;

    if (size < 2)
    {
        ft_printf("Array needs to have at least two elements to swap.\n");
        return;
    }
    temp = arr[0];
    arr[0] = arr[1];
    arr[1] = temp;
}

void swap_arrays(int a[], int b[], int size)
{
	int i;

	i = 0;
    while (i < size)
    {
        int temp = a[i];
        a[i] = b[i];
        b[i] = temp;
        i++;
    }
}