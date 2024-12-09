/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:28:09 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/09 14:42:32 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void radix_sort(int *a, int size_a, int *b, int size_b)
{
    while (size_b > 0)
    {
        if (a[0] < b[0])
        {
            pa_pb(&b, &size_b, &a, &size_a);
            ra_rb(b, size_b);
        }
        else
        {
            ra_rb(a, size_a);
        }
    }

    while (size_b <= size_a)
    {
        if (a[0] < b[0])
        {
            pa_pb(&b, &size_b, &a, &size_a);
        }
        ra_rb(b, size_b);
    }

    while (size_b <= size_a)
    {
        pa_pb(&b, &size_b, &a, &size_a);
        ra_rb(b, size_b);
    }
}

int main(int argc, char **argv)
{
    int *stack_a;
    int *stack_b;
    int size_a;
    int size_b;
    int i;

    if (argc < 2)
    {
        ft_printf("Error: Not enough arguments.\n");
        return 1;
    }

    size_a = argc - 1;
    size_b = 0;
    stack_a = ft_calloc(size_a, sizeof(int));
    stack_b = ft_calloc(size_a, sizeof(int)); // Allocate same size for stack_b initially

    i = 0;
    while (i < size_a)
    {
        stack_a[i] = ft_atoi(argv[i + 1]);
        i++;
    }

    // Apply radix sort
    radix_sort(stack_a, size_a, stack_b, size_b);

    // Clean up and exit
    free(stack_a);
    free(stack_b);
    return 0;
}