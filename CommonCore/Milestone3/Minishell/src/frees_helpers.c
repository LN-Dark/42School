/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:45:28 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/03/31 10:45:29 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_ms_components2(t_ms **ms)
{
	if ((*ms)->input)
	{
		ft_free_gnl(&(*ms)->input);
		(*ms)->input = NULL;
	}
	if ((*ms)->input_tmp)
	{
		free((*ms)->input_tmp);
		(*ms)->input_tmp = NULL;
	}
	if ((*ms)->str_add_to_tmp)
	{
		ft_free((*ms)->str_add_to_tmp);
		(*ms)->str_add_to_tmp = NULL;
	}
	if ((*ms)->input_cont)
	{
		free((*ms)->input_cont);
		(*ms)->input_cont = NULL;
	}
}

void	free_ms_components(t_ms **ms)
{
	if ((*ms)->file)
		free_lss((*ms)->file);
	if ((*ms)->pwd)
		free((*ms)->pwd);
	if ((*ms)->home)
		free((*ms)->home);
	if ((*ms)->oldpwd)
		free((*ms)->oldpwd);
	if ((*ms)->envp)
		ft_free((*ms)->envp);
	if ((*ms)->prompt)
	{
		free((*ms)->prompt);
		(*ms)->prompt = NULL;
	}
	if ((*ms)->tmpvar)
		ft_free((*ms)->tmpvar);
	if ((*ms)->str_redir)
		free((*ms)->str_redir);
	if ((*ms)->cmd)
		free((*ms)->cmd);
	if ((*ms)->fd_pipes)
		free((*ms)->fd_pipes);
	free_ms_components2(ms);
}

void	free_and_exit(t_ms **ms, int returnexit)
{
	free(*ms);
	exit(returnexit);
}
