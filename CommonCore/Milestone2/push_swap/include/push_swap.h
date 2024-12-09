/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:28:32 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/09 14:49:31 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

void sa_sb(int arr[], int size);
void ss(int a[], int b[], int size);
void pa_pb(int **stack_to, int *size_to, int **stack_from, int *size_from);
void ra_rb(int *arr, int size);
void rr(int *a, int size_a, int *b, int size_b);
void rra_rrb(int *arr, int size);
void rrr(int *a, int size_a, int *b, int size_b);

#endif