# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/31 10:46:42 by hfilipe-          #+#    #+#              #
#    Updated: 2025/04/01 12:51:05 by pcruz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MS_PATH = ./src
OBJ_DIR = ./obj
SRCS = $(addprefix $(MS_PATH)/, main.c readcmd.c expander.c expander2.c\
		handle_input.c handle_input_utils.c handle_input2.c export_quotes3.c \
		init.c init_utils.c frees.c execs.c pwd.c utils.c execs_errors.c \
		execve.c tmp_var.c echo.c signals.c pipes.c export_quotes.c \
		export.c export_utils.c export_errors.c export_concat.c export_utils2.c \
		export_existing_v.c unset.c env.c execute_envp_var.c add_to_tmpvar.c \
		cd.c cd_dot.c cd_slash.c cd_utils.c cd_ex_v.c cd_dash_slah.c \
		redirects.c redi_output.c redi_utils.c redi_heredoc.c export_quotes4.c\
		exit.c pipes_utils.c echo_utils.c export_quotes2.c export_quotes_ut.c \
		put_error.c replace_env_var.c utils2.c input_redirect.c redir_qt.c \
		exit_errors.c execute_envp_var2.c redi_utils2.c redi_utils3.c \
		handle_input3.c redi_heredoc2.c export_existing_v2.c init_shelllvl.c \
		heredoc_expand.c heredoc_expand2.c heredoc_expand3.c pipes_errors.c \
		export_existing_v1.c export_existing_v_1_1.c cd_quotes.c cd_slash2.c \
		cd_dash2.c export_new_ver.c export_quotes5.c redi_out_utils.c heredoc2.c \
		execve_2.c echo_handle_dollar.c echo_output_helpers.c \
		heredoc_extras.c frees_helpers.c cd_quotes2.c execve_3.c add_to_tmpvar2.c \
		handle_input_helpers.c execs2.c handle_input_heredoc.c redi_heredoc3.c \
		redirects_errors.c input_heredoc2.c handle_input1.c heredoc_utils.c \
		redi_heredoc4.c redi_remove_quotes.c signals2.c utils3.c echo_n.c \
		export_errors_quotes.c export_errors_quotes1.c export_errors_quotes2.c \
		init2.c export1.c export_variable_trim.c cd_slash3.c readcmd_helpers.c)
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
MINISHELL = minishell
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -ggdb -g 
LDFLAGS = -lreadline
RM = rm -f

all:		$(LIBFT) $(MINISHELL)

$(LIBFT):
		@$(MAKE) -C $(LIBFT_DIR)

$(MINISHELL):	$(LIBFT)	$(OBJS) 
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(MINISHELL) $(LDFLAGS)

sanitize: CFLAGS += -fsanitize=address
sanitize: re

$(OBJ_DIR)/%.o: $(MS_PATH)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

valgrind: 
	@echo "{\n   leak readline\n   Memcheck:Leak\n...\n   fun:readline\n}\n{\n   leak add_history\n   Memcheck:Leak\n...\n   fun:add_history\n}" > readline.supp
	@valgrind --suppressions=readline.supp --leak-check=full -s --show-leak-kinds=all ./$(MINISHELL)

clean:
	$(RM) -r $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean:		clean
	$(RM) $(MINISHELL)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re:			fclean all

.PHONY:		all clean fclean re sanitize valgrind