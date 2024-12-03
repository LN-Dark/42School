/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:28:32 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/03 16:10:51 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_stack {
    int value;
    struct s_stack *next;
} t_stack;

void push_swap(t_stack *a, t_stack **b);
t_stack *parse_arguments(int argc, char **argv);
void free_stack(t_stack *stack);
void push(t_stack **src, t_stack **dest);
void swap(t_stack *stack);
void rotate(t_stack **stack);
void reverse_rotate(t_stack **stack);
t_stack *create_new_node(int value);
void add_node_end(t_stack **stack, int value);
void push_all_to_a(t_stack **a, t_stack **b);
void push_all_to_b(t_stack **a, t_stack **b);
t_stack *find_smallest(t_stack *stack);
void print_stack(t_stack *stack);

#endif