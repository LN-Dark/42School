/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:28:32 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/13 10:45:00 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stlist
{
	struct s_stlist	*next;
	int				value;
	int				index;
}	t_stlist;

void	ra(t_stlist **head);
void	pa(t_stlist **stack_a, t_stlist **stack_b);
void	pb(t_stlist **stack_a, t_stlist **stack_b);
void	push(t_stlist **head, int new_data);
void	free_stack(t_stlist **head);
void	assign_indices(t_stlist *stack);
void	radix_sort(t_stlist **stack_a, t_stlist **stack_b);
void	bitwise_sort(t_stlist **stack_a, t_stlist **stack_b, int i);
void	sort_two(t_stlist **stack_a);
void	sort_three(t_stlist **stack_a);
void	rra(t_stlist **head);
void	sa(t_stlist **head);
void	sort_four(t_stlist **stack_a, t_stlist **stack_b);
void	sort_five(t_stlist **stack_a, t_stlist **stack_b);
int		stack_size(t_stlist *head);
int		is_sorted(t_stlist *head);
int		process_input_method_1(int argc, char **argv, t_stlist **stack_a);
int		process_input_method_0(int argc, char **argv, t_stlist **stack_a);
int		ft_is_repeated(t_stlist	*stack_a, int nb);
int		find_min_index(t_stlist *stack);

#endif
