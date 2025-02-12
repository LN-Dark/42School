# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 13:02:14 by pbranco-          #+#    #+#              #
#    Updated: 2025/01/08 09:55:25 by pcruz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/philosophers.c src/ft_atol.c

OBJS	= $(SRCS:.c=.o)

NAME	= philo

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
RM			= rm -f

all:		$(NAME)

$(NAME): $(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -lpthread

%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re