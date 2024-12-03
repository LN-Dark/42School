/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:07:07 by pbranco-          #+#    #+#             */
/*   Updated: 2024/12/03 14:57:14 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	count_map_height(t_game *game, char *file)
{
	int		fd;
	char	*line;

	game->map_height = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0 || ft_strcmp(file + (ft_strlen(file) - 4), ".ber") != 0)
		exit_game(game, "Error: Invalid map file.");
	line = get_next_line(fd);
	while (line != NULL)
	{
		game->map_height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	load_map(t_game *game, char *file)
{
	int		fd;
	char	*line;
	int		i;

	count_map_height(game, file);
	fd = open(file, O_RDONLY);
	game->map = (char **)ft_calloc(game->map_height, sizeof(char *));
	if (!game->map)
		exit_game(game, "Error: Memory allocation failed");
	i = 0;
	while (i < game->map_height)
	{
		line = get_next_line(fd);
		game->map[i] = line;
		i++;
	}
	close(fd);
	game->map_width = ft_strlen(game->map[0]) - 1;
	check_player_x_y(game);
}

void	render_tile(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collectible_img, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit_closed_img, x * TILE_SIZE, y * TILE_SIZE);
		if (game->exit_open)
			mlx_put_image_to_window(game->mlx, game->win,
				game->exit_open_img, x * TILE_SIZE, y * TILE_SIZE);
	}
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player_img, x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->ground_img, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
}
