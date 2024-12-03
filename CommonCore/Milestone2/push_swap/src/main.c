/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:28:09 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/03 15:32:56 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        return 1;
    }
    t_stack *a = parse_arguments(argc, argv);
    t_stack *b = NULL;

    if (!a) {
        write(2, "Error\n", 6);
        return 1;
    }

    push_swap(a, &b);
    free_stack(a);
    return 0;
}