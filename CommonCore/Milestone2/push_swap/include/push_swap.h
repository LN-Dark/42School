/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:28:32 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/11 11:15:35 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stlist
{
    int             value;
    int             index;
    struct s_stlist   *next;
}               t_stlist;

void	ss(t_stlist **stack_a, t_stlist **stack_b);
void	sb(t_stlist **head);
void	sa(t_stlist **head);
void	ra(t_stlist **head);
void	rb(t_stlist **head);
void	rr(t_stlist **stack_a, t_stlist **stack_b);
void	rra(t_stlist **head);
void	rrb(t_stlist **head);
void	rrr(t_stlist **stack_a, t_stlist **stack_b);
void	push(t_stlist **head, int new_data);
void	free_stack(t_stlist **head);
void	pa(t_stlist **stack_a, t_stlist **stack_b);
void	pb(t_stlist **stack_a, t_stlist **stack_b);
int		pop(t_stlist **head);
int		stack_size(t_stlist *head);

#endif