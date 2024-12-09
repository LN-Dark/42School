/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:28:32 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/09 15:36:58 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

void sa(int *stack_a, int size_a);
void sb(int *stack_b, int size_b);
void ss(int *stack_a, int size_a, int *stack_b, int size_b);
void ra(int *stack_a, int size_a);
void rb(int *stack_b, int size_b);
void rr(int *stack_a, int size_a, int *stack_b, int size_b);
void rra(int *stack_a, int size_a);
void rrb(int *stack_b, int size_b);
void rrr(int *stack_a, int size_a, int *stack_b, int size_b);
void pa(int *stack_a, int *size_a, int *stack_b, int *size_b);
void pb(int *stack_a, int *size_a, int *stack_b, int *size_b);

#endif