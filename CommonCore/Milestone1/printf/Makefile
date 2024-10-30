# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 13:02:14 by pbranco-          #+#    #+#              #
#    Updated: 2024/10/29 15:02:08 by pbranco-         ###   ########.fr        #
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
		ft_uitoa.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_itoa.c \
		ft_strdup.c \
		ft_strlen.c

OBJS	= ${SRCS:.c=.o}
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

NAME	= libftprintf.a

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

