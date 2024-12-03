/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:45:01 by pbranco-          #+#    #+#             */
/*   Updated: 2024/12/03 08:29:58 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int is_rectangle(t_game *game)
{
    int i;
    int width;

    if (!game->map || game->map_height == 0)
        return (0);
    i = 0;
    width = ft_strlen(game->map[0]);
    while (i < game->map_height - 1)
    {
        if (ft_strlen(game->map[i]) != width)
            return (0);
        i++;
    }
    return (1);
}

void check_walls(t_game *game)
{
    int i;

    i = 0;
    while (i < game->map_width)
    {
        if (game->map[0][i] != '1' || game->map[game->map_height - 1][i] != '1')
            exit_game(game, "Error: Map is not surrounded by walls.");
        i++;
    }
    i = 0;
    while (i < game->map_height)
    {
        if (game->map[i][0] != '1' || game->map[i][game->map_width - 1] != '1')
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
    while (y < game->map_height)
    {
        x = 0;
        while (x < game->map_width)
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

void validate_map(t_game *game)
{
    if (!is_rectangle(game))
        exit_game(game, "Error: Map is not rectangular.");
    check_walls(game);
    check_elements(game);
    if (game->collectibles <= 0 || game->exits != 1 || game->players != 1)
        exit_game(game, "Error: Map must contain 1 player, 1 exit, and at least 1 collectible.");
}