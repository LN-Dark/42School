/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:28:32 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/05 10:32:32 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

void swap_first_two(int arr[], int size);
void swap_arrays(int a[], int b[], int size);
void move_top(int **stack_to, int *size_to, int **stack_from, int *size_from);
void shift_bottom_to_top(int *arr, int size);
void rotate_both(int *a, int size_a, int *b, int size_b);
void rotate_top_to_bottom(int *arr, int size);
void rotate_both_top_to_bottom(int *a, int size_a, int *b, int size_b);

#endif