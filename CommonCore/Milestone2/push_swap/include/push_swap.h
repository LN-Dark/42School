/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:28:32 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/11 10:09:10 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_list
{
    int             value;
    int             index;
    struct t_list   *next;
}               t_list;

void	ss(t_list **stack_a, t_list **stack_b);
void	sb(t_list **head);
void	sa(t_list **head);
void	ra(t_list **head);
void	rb(t_list **head);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **head);
void	rrb(t_list **head);
void	rrr(t_list **stack_a, t_list **stack_b);
void	push(t_list **head, int new_data);
void	free_stack(t_list **head);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
int		pop(t_list **head);
int		stack_size(t_list *head);

#endif