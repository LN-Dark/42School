/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:16:47 by pbranco-          #+#    #+#             */
/*   Updated: 2024/11/29 10:18:29 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int is_valid(int x, int y, t_game *game, char **map)
{
    return (x >= 0 && y >= 0 && x < game->map_width && y < game->map_height && map[y][x] != 'F' && map[y][x] != '1');
}

void flood_fill_with_loop(t_game *game, int start_x, int start_y)
{
    t_point *stack;
    t_point p;
    int top;

    top = -1;
    stack = ft_calloc((game->map_width * game->map_height), sizeof(t_point));
    stack[++top] = (t_point){start_x, start_y};
    while (top >= 0)
    {
        p = stack[top--];
        if (is_valid(p.x, p.y, game, game->map) == 0)
            continue;
        if (game->map[p.y][p.x] == 'C')
            game->gathered++;
        if (game->map[p.y][p.x] == 'E')
            game->moves = 1;
        if (game->map[p.y][p.x] == 'E' && game->gathered != game->collectibles)
        {
            game->map[p.y][p.x] = 'F';
            continue;
        }
        game->map[p.y][p.x] = 'F';
        stack[++top] = (t_point){p.x + 1, p.y};
        stack[++top] = (t_point){p.x - 1, p.y};
        stack[++top] = (t_point){p.x, p.y + 1};
        stack[++top] = (t_point){p.x, p.y - 1};
    }
    free(stack);
    if(game->gathered != game->collectibles || game->moves != 1)
    	exit_game(game, "Error: No path available.");
}