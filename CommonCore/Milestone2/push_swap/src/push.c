/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:10:48 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/09 14:36:27 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void pa_pb(int **stack_to, int *size_to, int **stack_from, int *size_from)
{
    int *new_stack_to;
    int *new_stack_from;
	int i;

    if (*size_from == 0)
    {
        ft_printf("Source stack is empty, nothing to move.\n");
        return;
    }
    new_stack_to = ft_calloc((*size_to + 1), sizeof(int));
    // Copy existing elements to new_stack_to
    i = 0;
    while (i < *size_to)
    {
        new_stack_to[i + 1] = (*stack_to)[i];
        i++;
    }
    new_stack_to[0] = (*stack_from)[0];
    free(*stack_to);
    *stack_to = new_stack_to;
    (*size_to)++;
    i = 0;
    while (i < *size_from - 1)
    {
        (*stack_from)[i] = (*stack_from)[i + 1];
        i++;
    }
    new_stack_from = ft_calloc((*size_from - 1), sizeof(int));
    i = 0;
    while (i < *size_from - 1)
    {
        new_stack_from[i] = (*stack_from)[i];
        i++;
    }
    free(*stack_from);
    *stack_from = new_stack_from;
    (*size_from)--;
}

