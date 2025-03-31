/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:45:24 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:45:24 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_envp(t_ms	**ms)
{
	size_t	i;

	i = 0;
	while ((*ms)->envp[i] != NULL)
	{
		free((*ms)->envp[i]);
		i++;
	}
	free((*ms)->envp);
}

void	free_pipes(t_ms **ms)
{
	t_pipe	*tmp;
	t_pipe	*curr;

	curr = (*ms)->pipes;
	while (curr != NULL)
	{
		tmp = curr;
		if (curr->next != NULL)
		{
			curr = curr->next;
			ft_free_gnl(&tmp->text);
			free(tmp);
		}
		else
		{
			ft_free_gnl(&curr->text);
			free(curr);
			curr = NULL;
		}
	}
	(*ms)->pipes = NULL;
	(*ms)->nr_commands = 0;
	(*ms)->k = 0;
	(*ms)->i = 0;
}

void	free_lss(t_ls *head)
{
	t_ls	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		if (tmp != NULL)
		{
			if (tmp->file != NULL)
				free(tmp->file);
			free(tmp);
		}
	}
}

void	free_ms(t_ms **ms)
{
	int	returnexit;

	returnexit = (*ms)->exit_status;
	if ((*ms))
	{
		free_ms_components(ms);
		free_pipes(ms);
		free_and_exit(ms, returnexit);
	}
}

void	free_export(char *input, char **input2)
{
	if (input2)
	{
		ft_free(input2);
		input2 = NULL;
	}
	if (input)
		free(input);
}
