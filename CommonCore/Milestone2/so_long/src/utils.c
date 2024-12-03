/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:45:06 by pbranco-          #+#    #+#             */
/*   Updated: 2024/12/03 15:03:33 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	exit_game(t_game *game, char *msg)
{
	if (game->map)
		ft_free_solong(game);
	if (msg)
		ft_printf("%s\n", msg);
	exit(0);
}

void	ft_free_solong(t_game *game)
{
	int	i;

	if (!game || !game->map)
		return ;
	i = 0;
	while (i < game->map_height)
	{
		if (game->map[i])
		{
			free(game->map[i]);
			game->map[i] = NULL;
		}
		i++;
	}
	free(game->map);
	game->map = NULL;
}

t_game	ft_init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->map_width = 0;
	game->map_height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->collectibles = 0;
	game->players = 0;
	game->exits = 0;
	game->moves = 0;
	game->path_available = 0;
	game->exit_open = 0;
	game->wall_img = NULL;
	game->player_img = NULL;
	game->ground_img = NULL;
	game->collectible_img = NULL;
	game->exit_closed_img = NULL;
	game->exit_open_img = NULL;
	return (*game);
}

void	check_player_x_y(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
		y++;
	}
}