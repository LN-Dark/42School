/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:57:22 by pbranco-          #+#    #+#             */
/*   Updated: 2024/12/11 08:57:51 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	pop(struct s_node **head)
{
	struct s_node	*temp;
	int				popped_data;

	temp = *head;
	popped_data = temp->data;
	if (*head == NULL)
		return (-1);
	*head = (*head)->next;
	free(temp);
	return (popped_data);
}

void	push(struct s_node **head, int new_data)
{
	struct s_node	*new_node;

	new_node = (struct s_node *)malloc(sizeof(struct s_node));
	new_node->data = new_data;
	new_node->next = *head;
	*head = new_node;
}
