# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 10:37:54 by pbranco-          #+#    #+#              #
#    Updated: 2024/10/18 12:50:15 by pbranco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	get_next_line.c \
		get_next_line_utils.c \
		
OBJS	= ${SRCS:.c=.o}
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

NAME	= getNextLine.a

all:		$(NAME)

$(NAME):	$(OBJS)
				ar rcs $(NAME) $(OBJS)

%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
