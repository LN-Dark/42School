/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:45:19 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/03 11:04:52 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void handle_user_input(t_game *game)
{
    mlx_hook(game->win, 2, 1L<<0, handle_keypress, game);
}

int handle_keypress(int keycode, t_game *game)
{
    if (keycode == 65307)
        exit_game(game, NULL);
    else if (keycode == 119) // W key
        move_player(game, 0, -1);
    else if (keycode == 115) // S key
        move_player(game, 0, 1);
    else if (keycode == 97)  // A key
        move_player(game, -1, 0);
    else if (keycode == 100) // D key
        move_player(game, 1, 0);
    return (0);
}
void update_game_state(t_game *game)
{
    if (game->map[game->player_y][game->player_x] == 'C')
    {
        game->collectibles--;
        game->map[game->player_y][game->player_x] = '0';
        printf("Collectibles left: %d\n", game->collectibles);
        if (game->collectibles == 0)
        {
            game->exit_open = 1;
            printf("Exit is now open.\n");
        }
    }
    if (game->map[game->player_y][game->player_x] == 'E' && game->exit_open)
    {
        exit_game(game, "You Win!");
    }
}

void move_player(t_game *game, int dx, int dy)
{
    int new_x = game->player_x + dx;
    int new_y = game->player_y + dy;

    if (game->map[new_y][new_x] == '1')
        return; // Wall collision, do nothing
    game->map[game->player_y][game->player_x] = '0';
    game->player_x = new_x;
    game->player_y = new_y;
    game->map[game->player_y][game->player_x] = 'P';
    game->moves++;
    update_game_state(game);
    render_map(game);
}