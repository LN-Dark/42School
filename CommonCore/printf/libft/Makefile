# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 13:02:14 by pbranco-          #+#    #+#              #
#    Updated: 2024/10/29 14:05:31 by pbranco-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= 	ft_print_pointer.c \
			ft_print_unsigned.c \
			ft_printc.c \
			ft_printf.c \
			ft_printhex.c \
			ft_printnbr.c \
			ft_printstr.c \
			ft_put_hex.c \
			ft_uitoa.c

OBJS	= ${SRCS:.c=.o}
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -I ./libft
LIBFT	= libft

NAME	= libftprintf.a

all:		$(NAME)

$(NAME):	$(OBJS)
				@make -C $(LIBFT)
				@cp $(LIBFT)/libft.a .
				ar rcs $(NAME) $(OBJS)

%.o: %.c
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS)
				@make -C $(LIBFT) clean

fclean:		clean
				$(RM) $(NAME)
				@make -C $(LIBFT) fclean

re:			fclean all

.PHONY:		all clean fclean re

