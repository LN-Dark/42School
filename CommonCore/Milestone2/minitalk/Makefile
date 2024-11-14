# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 13:02:14 by pbranco-          #+#    #+#              #
#    Updated: 2024/11/14 13:40:53 by pbranco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_SERVER	= server.c
SRCS_CLIENT	= client.c

OBJS_SERVER	= $(SRCS_SERVER:.c=.o)
OBJS_CLIENT	= $(SRCS_CLIENT:.c=.o)

SERVER		= server
CLIENT		= client

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

all:		$(LIBFT) $(SERVER) $(CLIENT)

server:		$(LIBFT) $(SERVER)

client:		$(LIBFT) $(CLIENT)

$(LIBFT):
				@$(MAKE) -C $(LIBFT_DIR)

$(SERVER):	$(OBJS_SERVER) $(LIBFT)
				$(CC) $(CFLAGS) $^ -o $(SERVER)

$(CLIENT):	$(OBJS_CLIENT) $(LIBFT)
				$(CC) $(CFLAGS) $^ -o $(CLIENT)

%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)
				@$(MAKE) clean -C $(LIBFT_DIR)

fclean:		clean
				$(RM) $(SERVER) $(CLIENT)
				@$(MAKE) fclean -C $(LIBFT_DIR)

re:			fclean all

.PHONY:		all clean fclean re



