# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/29 13:02:14 by pbranco-          #+#    #+#              #
#    Updated: 2024/10/29 13:08:26 by pbranco-         ###   ########.fr        #
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
		
OBJS			= ${SRCS:.c=.o}
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I
LIBFT			= libft

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				@make -C $(LIBFT)
				@cp libft/libft.a .
				@mv libft.a $(NAME)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(LIBFT)/libft.a

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
