# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 13:02:14 by pbranco-          #+#    #+#              #
#    Updated: 2024/12/02 16:01:40 by pcruz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/main.c src/map.c src/validate_map.c src/utils.c src/validate_path.c src/init_game.c

OBJS	= $(SRCS:.c=.o)

SO_LONG		= so_long

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

MLX_DIR		= ./mlx
MLX			= $(MLX_DIR)/libmlx.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f

MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

all:		$(LIBFT) $(MLX) $(SO_LONG)

$(MLX):
				@if [ ! -d "$(MLX_DIR)" ]; then \
					echo "Cloning MiniLibX..."; \
					git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
				fi
				@$(MAKE) -C $(MLX_DIR)

$(LIBFT):
				@$(MAKE) -C $(LIBFT_DIR)

$(SO_LONG): $(LIBFT) $(MLX)	$(OBJS) 
				$(CC) $(CFLAGS) $(SRC) $^ $(MLX_FLAGS) -o $(SO_LONG)

%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS)
				@$(MAKE) clean -C $(LIBFT_DIR)
				@$(MAKE) clean -C $(MLX_DIR)

fclean:		clean
				$(RM) $(SO_LONG)
				@$(MAKE) fclean -C $(LIBFT_DIR)
				@$(MAKE) clean -C $(MLX_DIR)
				@if [ -d "$(MLX_DIR)" ]; then \
					echo "Removing MiniLibX..."; \
					rm -rf $(MLX_DIR); \
				fi

re:			fclean all

.PHONY:		all clean fclean re
