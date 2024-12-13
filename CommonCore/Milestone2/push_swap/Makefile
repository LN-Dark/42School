# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 13:02:14 by pbranco-          #+#    #+#              #
#    Updated: 2024/12/12 14:08:43 by pbranco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/main.c src/push.c src/rotate.c src/utils.c src/radix.c

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

$(PUSH_SWAP):	$(LIBFT)	$(OBJS) 
					$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(PUSH_SWAP)

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