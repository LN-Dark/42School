/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:16:47 by pbranco-          #+#    #+#             */
/*   Updated: 2024/12/03 08:33:49 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int is_valid(int x, int y, t_game *game, char **map)
{
    return (x >= 0 && y >= 0 && x < game->map_width && y < game->map_height && map[y][x] != 'F' && map[y][x] != '1');
}

void flood_fill_with_loop(t_game *game)
{
    t_point *stack;
    t_point p;
    int top;

    top = -1;
    stack = ft_calloc((game->map_width * game->map_height), sizeof(t_point));
    if (!stack)
        exit_game(game, "Error: Memory allocation failed");
    game->verify_collect = 0;
    game->path_available = 0;
    stack[++top] = (t_point){game->player_x, game->player_y};
    while (top >= 0)
    {
        p = stack[top--];
        if (is_valid(p.x, p.y, game, game->map) == 0)
            continue;
        if (game->map[p.y][p.x] == 'C')
            game->verify_collect++;
        if (game->map[p.y][p.x] == 'E')
            game->path_available = 1;
        if (game->map[p.y][p.x] == 'E' && game->verify_collect != game->collectibles)
        {
            game->map[p.y][p.x] = 'F';
            continue;
        }
        game->map[p.y][p.x] = 'F';
        if (top + 4 >= game->map_width * game->map_height)
        {
            free(stack);
            exit_game(game, "Error: Stack overflow");
        }
        stack[++top] = (t_point){p.x + 1, p.y};
        stack[++top] = (t_point){p.x - 1, p.y};
        stack[++top] = (t_point){p.x, p.y + 1};
        stack[++top] = (t_point){p.x, p.y - 1};
    }
    free(stack);
    if (game->verify_collect != game->collectibles || game->path_available != 1)
        exit_game(game, "Error: No path available.");
}