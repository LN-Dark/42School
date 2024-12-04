/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:16:47 by pbranco-          #+#    #+#             */
/*   Updated: 2024/12/04 11:24:11 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_valid(int x, int y, t_game *game)
{
	return (x >= 0 && y >= 0 && x < game->map_width
		&& y < game->map_height && game->map_temp[y][x] != 'F'
		&& game->map_temp[y][x] != '1');
}

void	process_tile(t_game *game, t_point p, t_point *stack, int *top)
{
	if (game->map_temp[p.y][p.x] == 'C')
		game->verify_collect++;
	if (game->map_temp[p.y][p.x] == 'E')
		game->path_available = 1;
	if (game->map_temp[p.y][p.x] == 'E'
		&& game->verify_collect != game->collectibles)
	{
		game->map_temp[p.y][p.x] = 'F';
		return ;
	}
	game->map_temp[p.y][p.x] = 'F';
	if (*top + 4 >= game->map_width * game->map_height)
	{
		free(stack);
		exit_game(game, "Error: Stack overflow");
	}
	stack[++(*top)] = (t_point){p.x + 1, p.y};
	stack[++(*top)] = (t_point){p.x - 1, p.y};
	stack[++(*top)] = (t_point){p.x, p.y + 1};
	stack[++(*top)] = (t_point){p.x, p.y - 1};
}

void	flood_fill_with_loop(t_game *game)
{
	t_point	*stack;
	t_point	p;
	int		top;

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
		if (is_valid(p.x, p.y, game) == 0)
			continue ;
		process_tile(game, p, stack, &top);
	}
	free(stack);
	if (game->verify_collect != game->collectibles || game->path_available != 1)
		exit_game(game, "Error: No path available.");
}
