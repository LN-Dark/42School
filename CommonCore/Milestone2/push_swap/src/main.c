/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:28:09 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/05 14:39:20 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void optimized_sort(int *stack_a, int *stack_b, int size_a, int size_b)
{
    // Exemplo de estratégia para otimização
    // Dividir o stack_a em dois e mover metade para stack_b
    int mid = size_a / 2;
    for (int i = 0; i < mid; i++)
    {
        move_top(&stack_b, &size_b, &stack_a, &size_a);
        ft_printf("pb\n");
    }

    // Ordenar as duas metades separadamente
    for (int i = 0; i < mid - 1; i++)
    {
        if (stack_a[i] > stack_a[i + 1])
        {
            swap_first_two(stack_a, size_a);
            ft_printf("sa\n");
        }
    }
    for (int i = 0; i < size_b - 1; i++)
    {
        if (stack_b[i] > stack_b[i + 1])
        {
            swap_first_two(stack_b, size_b);
            ft_printf("sb\n");
        }
    }

    // Combinar as duas metades de volta em stack_a
    while (size_b > 0)
    {
        move_top(&stack_a, &size_a, &stack_b, &size_b);
        ft_printf("pa\n");
    }

    // Ajustar a ordem final com rotações se necessário
    for (int i = 0; i < size_a - 1; i++)
    {
        if (stack_a[i] > stack_a[i + 1])
        {
            shift_bottom_to_top(stack_a, size_a);
            ft_printf("ra\n");
        }
    }
}

int main(int argc, char **argv) {
    int i = 0;
    int size_a = argc - 1;
    int size_b = 0;
    int *stack_a = ft_calloc(size_a, sizeof(int));
    int *stack_b = ft_calloc(size_b, sizeof(int));

    if (argc < 2) {
        ft_printf("Usage: %s <integers to sort>\n", argv[0]);
        return 1;
    }
    i = 0;
    while (i < size_a){
        stack_a[i] = ft_atoi(argv[i + 1]);
        i++;
    }

    optimized_sort(stack_a, stack_b, size_a, size_b);

    if(stack_b)
        free(stack_b);
    
    return 0;
}