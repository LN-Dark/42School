/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 08:55:03 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:40:44 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/minishell.h"

char	**init_envp2(char **new_envp, int i)
{
	new_envp[i] = 0;
	while (--i >= 0)
		new_envp[i] = 0;
	return (new_envp);
}

void	init_envp1(t_ms **ms, char **envp, int i)
{
	char	**new_envp;
	size_t	j;

	while (envp[i])
		i++;
	new_envp = (char **)ft_calloc((i + 1), sizeof(char *));
	new_envp = init_envp2(new_envp, i);
	i = 0;
	while (envp[i])
	{
		if (ft_strchr(envp[i], '=') != NULL)
		{
			new_envp[i] = ft_strdup(envp[i]);
			j = 0;
			while (new_envp[j])
			{
				if (i >= 1 && ft_strcmp(new_envp[j], new_envp[i]) > 0)
					swap(&new_envp[j], &new_envp[i]);
				j++;
			}
		}
		i++;
	}
	new_envp[i] = NULL;
	(*ms)->envp = new_envp;
}

void	init_envp(t_ms **ms, char **envp)
{
	int		i;

	i = 0;
	if (!envp || envp[0] == NULL)
		init_envp_empty(ms);
	else
	{
		init_envp1(ms, envp, i);
		(*ms)->input_if_needed = NULL;
		(*ms)->no_envp = 0;
	}
}

void	init_ms(t_ms **ms, char **envp)
{
	t_ls	*file;

	file = NULL;
	(*ms) = ft_calloc(1, sizeof(t_ms));
	(*ms)->file = file;
	init_envp(ms, envp);
	(*ms)->pwd = getcwd(NULL, 0);
	(*ms)->exit_status = 0;
	(*ms)->is_exit = 0;
	(*ms)->tmpvar = NULL;
	(*ms)->nr_commands = 0;
	if ((*ms)->envp)
		init_oldpwd(ms);
	if ((*ms)->envp)
		init_home(ms);
	(*ms)->tmppipe = NULL;
	(*ms)->k = 0;
	(*ms)->i = 0;
	(*ms)->export_in = NULL;
	(*ms)->quotes_type = 0;
	(*ms)->tmpvar = NULL;
	(*ms)->input = NULL;
	(*ms)->last_here_cmd = NULL;
	(*ms)->cd = 0;
	init_shelllvl(ms);
}
