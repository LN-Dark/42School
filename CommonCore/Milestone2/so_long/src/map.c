/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:07:07 by pbranco-          #+#    #+#             */
/*   Updated: 2024/11/29 10:08:14 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void load_map(t_game *game, char *file)
{
    int fd;
    char *line;
    int i;

    fd = open(file, O_RDONLY);
    i = 0;
    if (fd < 0)
        exit_game(game, "Error: Invalid map file.");
    if(ft_strcmp(file + (ft_strlen(file) - 4), ".ber") != 0)
    	exit_game(game, "Error: Invalid map file.");
    while ((line = get_next_line(fd)) > 0)
        i++;
    close(fd);
    game->map = ft_calloc(i, sizeof(char **));
    i = 0;
    fd = open(file, O_RDONLY);
    while ((line = get_next_line(fd)) > 0)
    {
        game->map[i++] = line;
        printf("game->map: %s", game->map[i-1]);
        
    }
    game->map[i] = NULL;
    game->map_height = i;
    game->map_width = ft_strlen(game->map[0]);
    close(fd);
}