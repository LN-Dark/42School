/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:37:06 by pbranco-          #+#    #+#             */
/*   Updated: 2024/12/02 16:15:42 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(int argc, char **argv)
{
    t_game game;

    game = ft_init_game(&game);
    if (argc != 2)
        return (ft_printf("Usage: ./so_long <map_file>\n"));
    load_map(&game, argv[1]);
    validate_map(&game);
    load_images(&game);
    initialize_window(&game);
    mlx_loop_hook(game.mlx, main_loop, &game);
    mlx_loop(game.mlx);
    return (0);
}

int main_loop(t_game *game)
{
    render_map(game);
    mlx_loop(game->mlx);
    return (0);
}