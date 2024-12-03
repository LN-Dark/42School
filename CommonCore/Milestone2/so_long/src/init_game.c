/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:56:43 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/03 08:35:13 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void load_images(t_game *game)
{
    int img_width;
    int img_height;

    game->players = 0;
    game->exits = 0;
    game->moves = 0;
    game->exit_open = 0;
    game->mlx = mlx_init();
    if (!game->mlx)
        exit_game(game, "Error: MLX initialization failed");
    game->wall_img = mlx_xpm_file_to_image(game->mlx, "./assets/wall.xpm", &img_width, &img_height);
    game->player_img = mlx_xpm_file_to_image(game->mlx, "./assets/player.xpm", &img_width, &img_height);
    game->ground_img = mlx_xpm_file_to_image(game->mlx, "./assets/ground.xpm", &img_width, &img_height);
    game->collectible_img = mlx_xpm_file_to_image(game->mlx, "./assets/key.xpm", &img_width, &img_height);
    game->exit_closed_img = mlx_xpm_file_to_image(game->mlx, "./assets/exit-closed.xpm", &img_width, &img_height);
    game->exit_open_img = mlx_xpm_file_to_image(game->mlx, "./assets/open-exit.xpm", &img_width, &img_height);
    if (!game->wall_img || !game->player_img || !game->collectible_img || !game->exit_closed_img || !game->exit_open_img)
        exit_game(game, "Error: Failed to load images");
}

void initialize_window(t_game *game)
{
    game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE, game->map_height * TILE_SIZE, "so_long");
    if (!game->win)
        exit_game(game, "Error: Window creation failed");
}