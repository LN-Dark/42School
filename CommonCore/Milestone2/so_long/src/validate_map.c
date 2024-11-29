/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:45:01 by pbranco-          #+#    #+#             */
/*   Updated: 2024/11/29 10:09:38 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void check_rectangle(t_game *game)
{
    int y;
    int width;

    y = 0;
    width = ft_strlen(game->map[0]);
    while (y < game->map_height - 1)
    {
        if (ft_strlen(game->map[y]) != width)
            exit_game(game, "Error: Map is not rectangular.");
        y++;
    }
    game->map_width = width;
}

void check_walls(t_game *game)
{
    int i;

    i = 0;
    while (i < game->map_width - 1)
    {
        if (game->map[0][i] != '1' || game->map[game->map_height - 1][i] != '1')
            exit_game(game, "Error: Map is not surrounded by walls.");
        i++;
    }
    i = 0;
    while (i < game->map_height)
    {
        if (game->map[i][0] != '1' || game->map[i][game->map_width - 2] != '1')
            exit_game(game, "Error: Map is not surrounded by walls.");
        i++;
    }
}

void check_elements(t_game *game)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < game->map_height - 1)
    {
        x = 0;
        while (x < game->map_width - 1)
        {
            if (game->map[y][x] == 'P')
                game->players++;
            else if (game->map[y][x] == 'E') 
                game->exits++;
            else if (game->map[y][x] == 'C') 
                game->collectibles++;
            else if (game->map[y][x] != 'C' && game->map[y][x] != 'E'
                && game->map[y][x] != 'P' && game->map[y][x] != '1' && game->map[y][x] != '0'){ 
                exit_game(game, "Error: Map must contain only P, C, E, 0, 1.");

            }
            x++;
        }
        y++;
    }
}

void    ft_check_route(t_game *game)
{
    if (game->player_y < 0 || game->player_y >= game->map_height
        || game->player_x < 0 || game->player_x >= game->map_width
        || game->map[game->player_y][game->player_x] != '0')
        return;

    game->map[game->player_y][game->player_x] = '0';
    ft_check_route(game);
    ft_check_route(game);
    ft_check_route(game);
    ft_check_route(game);
}

void validate_map(t_game *game)
{
    check_rectangle(game);
    check_walls(game);
    check_elements(game);
    if (game->collectibles <= 0 || game->exits != 1 || game->players != 1)
        exit_game(game, "Error: Map must contain 1 player, 1 exit, and at least 1 collectible.");
    check_player_x_y(game);
    flood_fill_with_loop(game, game->player_x, game->player_y);
}
