/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 08:45:19 by pcruz             #+#    #+#             */
/*   Updated: 2024/12/03 13:03:45 by pcruz            ###   ########.fr       */
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
    else if (keycode == 119)
        move_player(game, 0, -1);
    else if (keycode == 115)
        move_player(game, 0, 1);
    else if (keycode == 97)
        move_player(game, -1, 0);
    else if (keycode == 100)
        move_player(game, 1, 0);
    return (0);
}
void update_game_state(t_game *game)
{
    if (game->map[game->player_y][game->player_x] == 'C')
    {
        game->collectibles--;
        game->map[game->player_y][game->player_x] = '0';
        if (game->collectibles <= 0)
            game->exit_open = 1;
    }
    if (game->map[game->player_y][game->player_x] == 'E' && game->exit_open)
    {
        exit_game(game, "You Win!");
    }
    if (game->map[game->player_y][game->player_x] == '0')
    {
    	game->map[game->player_y][game->player_x] = 'P';
    }
}

void move_player(t_game *game, int dx, int dy)
{
    if (game->map[game->player_y + dy][game->player_x + dx] == '1')
        return;
    game->player_x = game->player_x + dx;
    game->player_y = game->player_y + dy;
    game->map[game->player_y - dy][game->player_x - dx] = '0';
    game->moves++;
    ft_printf("New coordinates x - %d, y - %d, move nº %d\n", game->player_x, game->player_y, game->moves);
    update_game_state(game);
    render_map(game);
}