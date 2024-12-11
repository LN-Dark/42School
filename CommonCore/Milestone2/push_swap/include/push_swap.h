/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:28:32 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/11 08:55:26 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

struct	s_node
{
	int			data;
	struct Node	*next;
}

void	rr(struct Node **stack_a, struct Node **stack_b);
void	rb(struct Node **head);
void	ra(struct Node **head);
void	rra(struct Node **head);
void	rrb(struct Node **head);
void	rrr(struct Node **stack_a, struct Node **stack_b);
void	pa(struct Node **stack_a, struct Node **stack_b);
void	pb(struct Node **stack_a, struct Node **stack_b);
void	sa(struct Node **head);
void	sb(struct Node **head);
void	ss(struct Node **stack_a, struct Node **stack_b);
void	push(struct Node **head, int new_data);
int		pop(struct Node **head);

#endif