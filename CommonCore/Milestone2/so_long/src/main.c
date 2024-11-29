/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:37:06 by pbranco-          #+#    #+#             */
/*   Updated: 2024/11/28 11:13:34 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"



int main(int argc, char **argv)
{
    t_game game;

    game = ft_init_game(&game);
    if (argc != 2)
        return (ft_printf("Usage: ./so_long <map_file>\n"));
    load_map(&game, argv[1]);
    validate_map(&game);
    
    return (0);
}