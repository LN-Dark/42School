# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 13:02:14 by pbranco-          #+#    #+#              #
#    Updated: 2024/12/03 16:01:14 by pcruz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/main.c src/operations.c src/parse_arguments.c src/push_swap.c

OBJS	= $(SRCS:.c=.o)

PUSH_SWAP	= push_swap

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f

all:		$(LIBFT) $(PUSH_SWAP)

$(LIBFT):
				@$(MAKE) -C $(LIBFT_DIR)

$(PUSH_SWAP): $(LIBFT)	$(OBJS) 
				$(CC) $(CFLAGS) $(SRC) -o $(PUSH_SWAP)

%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS)
				@$(MAKE) clean -C $(LIBFT_DIR)

fclean:		clean
				$(RM) $(PUSH_SWAP)
				@$(MAKE) fclean -C $(LIBFT_DIR)

re:			fclean all

.PHONY:		all clean fclean re
