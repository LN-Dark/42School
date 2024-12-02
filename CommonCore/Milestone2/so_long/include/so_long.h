/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:37:45 by pbranco-          #+#    #+#             */
/*   Updated: 2024/12/02 16:39:26 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 60

# include "../mlx/mlx.h"
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_game {
    void    *mlx;
    void    *win;
    char    **map;
    int     map_width;
    int     map_height;
    int     player_x;
    int     player_y;
    int     collectibles;
    int     gathered;
    int     players;
    int     exits;
    int     moves;
    int     path_available;
    int     verify_collect;
    int     exit_open;
    void    *wall_img;
    void    *ground_img;
    void    *player_img;
    void    *collectible_img;
    void    *exit_closed_img;
    void    *exit_open_img;
} t_game;

typedef struct s_path{
    int x;
    int y;
} t_point;

void    validate_map(t_game *game);
void    exit_game(t_game *game, char *msg);
void load_map(t_game *game, char *file);
void    ft_free_solong(t_game *game);
int main(int argc, char **argv);
t_game  ft_init_game(t_game *game);
void check_player_x_y(t_game *game);
void flood_fill_with_loop(t_game *game, int start_x, int start_y);
int is_valid(int x, int y, t_game *game, char **map);
void initialize_game(t_game *game);
void load_images(t_game *game);
void render_map(t_game *game);
void initialize_window(t_game *game);
int main_loop(t_game *game);

#endif
