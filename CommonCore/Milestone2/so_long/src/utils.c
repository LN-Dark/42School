/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:45:06 by pbranco-          #+#    #+#             */
/*   Updated: 2024/12/04 11:23:36 by pbranco-         ###   ########.fr       */
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

int	exit_game_clean(t_game *game)
{
	if (game->map)
		ft_free_solong(game);
	exit(0);
}

void	ft_free_solong(t_game *game)
{
	int	i;

	if (!game || !game->map)
		return ;
	i = -1;
	while (++i < game->map_height)
	{
		free(game->map[i]);
		free(game->map_temp[i]);
	}
	free(game->map);
	free(game->map_temp);
	ft_destroymlx(game);
	game->map = NULL;
	game->map_temp = NULL;
}

void	ft_destroymlx(t_game *game)
{
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->ground_img)
		mlx_destroy_image(game->mlx, game->ground_img);
	if (game->collectible_img)
		mlx_destroy_image(game->mlx, game->collectible_img);
	if (game->exit_closed_img)
		mlx_destroy_image(game->mlx, game->exit_closed_img);
	if (game->exit_open_img)
		mlx_destroy_image(game->mlx, game->exit_open_img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

t_game	ft_init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->map = NULL;
	game->map_temp = NULL;
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
