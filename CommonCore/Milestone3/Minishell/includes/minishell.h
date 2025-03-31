/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:14:29 by pbranco-          #+#    #+#             */
/*   Updated: 2025/03/31 10:44:33 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <limits.h>
# include <dirent.h>
# include <fcntl.h>
# include <signal.h>
# include <termios.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdbool.h>
# include <signal.h>
# include <errno.h>

# define ERROR_CMD " command not found\n"
# define ERROR_CMD_ "%s: command not found\n"
# define ERROR_ENV "env: '%s': No such file or directory\n"
# define ERROR_ARG "minishell: exit: too many arguments\n"
# define ERROR_CD "minishell: cd: too many arguments\n"
# define ERROR_NUM_ARG "minishell: %s: numeric argument required\n"
# define ERROR_IS_DIR "minishell: %s: Is a directory\n"
# define ERROR_PERMS "minishell: %s: Permission denied\n"
# define ERROR_ECHO "syntax error near unexpected token 'newline'\n"
# define ERROR_SNTAX "syntax error near unexpected token '%s'\n"
# define ERROR_EXP_P "minshell: export: '%s': not a valid identifier\n"
# define ERROR_EXP_M "minshell: export: =: invalid option\n"
# define ERROR_FORD "minshell: %s: No such file or directory\n"
# define ERROR_QT "minshell: %s: The project should not handle \
unclosed quotes!\n"
# define ERROR_HERE "minishell: warning: here-document \
delimited by end-of-file (wanted `%s')\n"
# define ERROR_NRBS "minshell: '%s' not required by subject\n"
# define BG_BLUE "\033[44m"
# define BOLD "\033[1m"
# define RESET "\033[0m"

extern volatile int	g_signal;

typedef struct rep_env_vars
{
	char	*result;
	char	*dollar_pos;
	char	*var;
	char	*end;
	char	*value;
	size_t	var_len;
	char	*new_result;
	size_t	result_len;
	size_t	value_len;
	size_t	new_result_len;
}	t_replace_env_vars;

typedef struct replace_vars
{
	char	*str;
	char	*needle;
	char	*replace;
	char	*result;
	char	*tmp;
	size_t	len_needle;
	size_t	len_replace;
	size_t	len_front;
	int		count;
}	t_replace_vars;

typedef struct pipe_struct
{
	char				*text;
	int					*fd;
	struct pipe_struct	*next;
}	t_pipe;

typedef struct ls_struct
{
	char				*file;
	struct ls_struct	*next;
}	t_ls;

typedef struct rd_struct
{
	int		check1;
	int		check2;
	size_t	i;
	char	c;
}	t_rd;

typedef struct here_struct
{
	char	*bff;
	char	*bff2;
	char	*n_str;
	char	*n_str2;
	char	**split2;
	char	**split_cmd;
}	t_hered;

typedef struct s_check_option_n
{
	int	j;
	int	h;
	int	len_init;
	int	display_newline;
}	t_check_option_n;

typedef struct ms_struct
{
	t_ls	*file;
	t_pipe	*pipes;
	t_rd	redi;
	t_hered	h;
	char	**export;
	char	*pwd;
	char	*oldpwd;
	char	*home;
	char	**envp;
	char	**tmpvar;
	char	*tmppipe;
	int		exit_status;
	int		is_exit;
	size_t	k;
	size_t	i;
	size_t	p;
	size_t	j;
	size_t	a;
	size_t	x;
	size_t	y;
	size_t	m;
	size_t	n;
	size_t	c;
	int		no_envp;
	int		check_inpt;
	int		nr_commands;
	char	**export_in;
	int		exp_start;
	int		quotes_type;
	char	**redir;
	char	*var_name;
	char	*pwd_shell;
	char	*str_exp;
	int		h_found;
	char	*prompt;
	char	*cmd;
	char	*str_e;
	char	*str_redir;
	int		*fd_pipes;
	char	*str_here;
	char	*input;
	char	*input_tmp;
	char	*input_cont;
	char	**str_add_to_tmp;
	char	*input_expand;
	char	*hdc_nm;
	int		here_check;
	char	*last_here_cmd;
	int		cd;
	int		not_expand;
	int		found2q;
	char	*input_if_needed;
}	t_ms;

void	ft_readcmd(t_ms **ms);
void	handle_input(t_ms **ms, int type);
void	builtin_echo(char input[LINE_MAX], t_ms **ms);
int		pwd(t_ms **ms);
void	builtin_cd(char *input, t_ms **ms);
void	init_ms(t_ms **ms, char **envp);
void	process_pipes(t_ms **ms, size_t i);
void	choose_builtin(char *command, t_ms **ms);
void	process_redirects(char *command, t_ms **ms);
void	handle_export(char *comand, t_ms **ms);
void	print_env(t_ms **ms, char *cmd);
void	unset(char *comand, t_ms **ms);
void	ft_free(char **strs);
void	free_ms(t_ms **ms);
void	free_lss(t_ls *head);
void	free_pipes(t_ms **ms);
void	free_envp(t_ms **ms);
char	*escape_middle_quotes(char *command);
char	*ft_replace_word(char *str, char *needle, char *replace);
void	insert_string_order(char **arr, char *input, t_ms **ms);
char	*ft_strstr_(const char *haystack, const char *needle);
char	*ft_strstr_1(const char *haystack, const char *needle);
void	swap(char **str1, char **str2);
int		ft_strchr_(char *input, size_t j);
int		check_e(t_ms **ms);
void	concat_vr_value(char *input, t_ms **ms, size_t j, size_t x);
int		ft_strcmp_(char *s1, char *s2);
char	*remove_1st_word(char *string);
void	signal_handler(int sig);
void	init_home(t_ms **ms);
void	init_oldpwd(t_ms **ms);
char	*get_env_var_value(t_ms **ms, char *var);
void	free_export(char *input, char **input2);
void	export_existing_v(char *input, t_ms **ms);
void	handle_cd_dot(t_ms **ms);
void	cd_slash(char *input, t_ms **ms);
char	*remove_quotes(char *input);
int		check_input_args(char *input, t_ms **ms);
char	*remove_spaces_end(char *input2);
void	cd_ex_v(char *input, t_ms **ms);
void	cd_home(t_ms **ms, char *input);
void	cd_dash(t_ms **ms);
void	cd_no_slash(t_ms **ms, char *input);
void	builtin_exit(char *command, t_ms **ms);
char	*get_path(char *cmd, char **envp);
void	execute_variable(char *command, t_ms **ms, char **cmdsplit);
void	add_tmp_var(char *input, t_ms **ms, char **cmd);
int		execs_error(char *command, t_ms **ms);
void	realoc_tmp(char *input, t_ms **ms);
char	*replace_env_vars(char *str, t_ms **ms);
char	*ft_remove_special_chars(char *str);
void	execute_pipe(char *command, t_ms **ms);
void	ft_put_error(char *str_error, char *needle, char *result);
char	*remove_redir(char *command, char c, int nb, t_ms **ms);
char	*get_str(char *command, char c, int nb, t_ms **ms);
void	output_redirect(t_ms **ms, char *command_trim);
void	output_append(t_ms **ms, char *cmd_trim);
void	heredoc(char *command, t_ms **ms);
void	handltmp(t_ms **ms, char *str);
char	*get_str2(t_ms **ms, char *str);
char	*get_str1(t_ms **ms, char *cmd);
void	set_curr(t_ms **ms, t_pipe *new);
int		check_unclose_quotes(char *cmd);
void	node1(t_ms **ms, size_t check, char *cmd);
void	nextnodes(t_ms **ms, char *cmd, size_t check);
void	allocate_pipes(int **fd, size_t nr_commands, t_ms **ms);
void	close_pipes(int *fd, size_t count);
void	setup_child_pipes(int *fd, size_t j, size_t nr_commands, t_ms **ms);
void	execute_child(t_pipe *curr, int *fd, size_t j, t_ms **ms);
void	wait_for_children(pid_t pid, size_t nr_commands, t_ms **ms);
void	cd_no_slash(t_ms **ms, char *input);
void	cd_dash(t_ms **ms);
void	export_quotes(char *input, t_ms **ms);
void	export_1arg(char *input, t_ms **ms);
char	*expander(char *command, t_ms **ms);
char	*get_extracmd1(char *cmd, char *input);
int		handle_export2(char **input, t_ms **ms);
void	print_export(t_ms **ms);
void	add_to_array(t_ms **ms, size_t i, char *input, int quotes);
size_t	args_no_equal(size_t i, char *input, t_ms **ms);
char	*putbar(char *input);
void	add_to_struct(t_ms **ms, char *n_input);
void	add_with_s_qt(t_ms **ms, size_t i, char *input);
void	add_with_d_qt(t_ms **ms, size_t i, char *input);
void	g_signal_handler(t_ms **ms);
char	*check_other_redir(char *str);
int		i_string_enclosed(char *str);
void	show_pipes_error(int *fd, size_t count, t_ms **ms);
int		handle_env_var_echo(char *cmd, t_ms **ms);
void	alloc_for_pipe(char *cmd, t_ms **ms, size_t check);
size_t	export_quotes3(char *input, t_ms **ms, size_t i);
int		redirect_quotes(char *command_trim);
void	input_redirect(t_ms **ms, char *cmd_trim);
char	*search_tmpvar(t_ms **ms, char *input);
size_t	get_i(char *input, size_t i);
size_t	export_quotes4(char *input, t_ms **ms, size_t i);
int		is_too_big(char *num);
void	handle_exit_with_no_num_arguments(char *cmd, t_ms **ms);
void	handle_exit_valid_arguments(char *cmd, t_ms **ms);
void	handle_exit_with_too_many_arguments(char *cmd, t_ms **ms);
int		has_unquoted_semicolon_or_asterisk(char *str);
int		command_has_args_or_flags(char *cmd);
void	found_var(char *input2, t_ms **ms, size_t i, char *command);
char	*get_extracmd(char *cmd);
char	*remove_strq(char *str);
void	gofowardpipes(t_ms **ms, char *cmd);
void	free_exit_heredoc(t_ms **ms, char *e_o_f);
int		check_eof_her(char *cmd);
void	heredoc4(t_ms **ms, char *e_o_f);
int		is_valid_env_var_name(char *name);
char	*get_new_var_name(char *var_name, t_ms **ms);
int		get_check(t_ms **ms, char *input2, int check, size_t *i);
char	*envvar(char *input2, t_ms **ms, size_t i, char *command);
void	init_shelllvl(t_ms **ms);
void	change_shelllevel(t_ms **ms);
char	*expand_heredoc(t_ms **ms, int n, char *str);
char	*get_var(char *n_str, t_ms **ms);
char	*n_str_heredoc(char **str2, int n);
char	*get_the_rest(char *str, size_t j, int n, char *str2);
char	*get_expansion(char *str, t_ms **ms);
void	heredoc3_1(t_ms **ms);
char	*get_slash(char *str);
char	*get_concat_in(char *input);
size_t	get_i_(char *input, size_t i, size_t *j);
size_t	get_i_ex(t_ms **ms, int *check, char *ex_var_name);
void	free_exv(char *str, char *str2, char *str3);
void	export_existing_v3(char *var_name, char *str, t_ms **ms, \
char *ex_var_name);
int		check_export_variable(char *str, char *str2);
int		compeof(char *e_o_f, t_ms **ms);
char	*get_var_name2(size_t j, char *input, size_t i);
int		ft_strlen_abc(char *str, char a, char b, char c);
int		search_pwd(t_ms **ms, int nb);
void	cd_quotes(t_ms **ms, char *input);
char	*cd_slash_dots(char *input, t_ms **ms);
char	*remove_quotes_execute(char *command);
void	concat_and_export(char *var_name, char *ex_var_name, t_ms **ms);
int		*check_for_exp(int *check, size_t i, char *input);
void	set_pipe_vars(t_ms **ms);
int		check_pipe_errors(t_ms **ms);
void	cd_dash3(t_ms **ms);
void	cd_home_error(t_ms **ms);
int		check_dash_existingv(char *input, t_ms **ms);
char	*export_quotes5(char *input, size_t *i, t_ms **ms);
int		search_for_quotes(char *cmd, char c);
void	get_without_quotes(char *cmd, char c, t_ms **ms);
char	*get_str_and_check(t_ms **ms, size_t *h, char *cmd, int nb);
int		file_no_name(char *cmd);
void	child_call(t_ms **ms, char *cmd);
char	*remove_quotes_heredoc(char *cmd, t_ms **ms);
void	add_command_extra(t_ms **ms);
int		is_valid_number(char *str);
void	fd_error(t_ms**ms, char *str, int nb);
void	check_str_output(char *str, t_ms **ms);
void	exit_from_execve(t_ms **ms, char **cmd, char *av, int nb);
char	*ft_get_s_quotes(char *cmd);
char	*ft_get_d_quotes(char *cmd);
void	handle_dollar_sign_special_cases(char cmd, t_ms **ms);
void	handle_single_quotes(char *input, int *i, t_ms **ms, int type);
void	handle_double_quotes(char *input, int *i, t_ms **ms);
void	skip_initial_spaces(char *input, int *i);
int		check_display_newline(char *input, int *i);
void	handle_dollar_sign(char *cmd, t_ms **ms, int *i);
void	skip_leading_control_chars(char *cmd, int *i);
void	free_ms_components(t_ms **ms);
void	free_and_exit(t_ms **ms, int returnexit);
void	check_extra_heredoc(t_ms **ms);
char	*cd_quotes2(t_ms **ms, char *input, size_t *i, int *check);
void	realoc_tmp(char *input, t_ms **ms);
void	addtmp(char *input, t_ms **ms);
char	*get_path(char *cmd, char **envp);
void	handle_quoted_input(char *new_input, t_ms **ms, \
t_pipe *new_pipe, size_t i);
void	split_and_handle_pipes(t_ms **ms);
void	extend_input_if_needed(t_ms **ms, int n);
int		handle_pipe_errors_2(t_ms **ms);
void	handle_input2(char **dividedpipes, t_ms **ms, size_t i);
void	add_with_quotes(char *cmd, t_ms **ms, t_pipe *new_pipe, size_t i);
void	control_d(t_ms **ms, char *e_o_f);
int		check_mini_pipe(char *input, t_ms **ms);
int		handle_redi(char *command_trim, t_ms **ms, int redirect_type);
void	process_redirects2(char *command, t_ms **ms);
int		check_and_or(char *input1);
char	*check_here_pipes(char *input, t_ms **ms);
void	signal_handler_heredoc(int sig);
void	signal_global(t_ms **ms);
void	signal_global_heredoc(t_ms **ms);
int		control_d_exit(t_ms **ms, char *e_o_f);
void	control_c_exit(t_ms **ms, char *e_o_f);
int		check_command_before(t_ms **ms, char *e_o_f);
char	*remove_word(char *e_o_f);
int		check_redir(char *cmd);
void	free_exit_heredoc2(t_ms **ms, char *e_o_f);
void	echo_output_direct(char *input, t_ms **ms, int type);
void	execute_first_here(t_ms **ms, char *input);
void	heredoc_rm(t_ms **ms);
int		heredoc_creat_file(t_ms **ms);
char	*join_name(t_ms**ms);
void	heredoc_child(char *command, t_ms **ms);
void	check_extra_heredoc1(t_ms **ms);
int		handle_input_if(t_ms **ms);
void	free_controld(t_ms **ms);
void	heredoc4_1(t_ms **ms);
char	*redi_get_str_quotes(char *str, size_t *h, t_ms**ms);
int		count_quotes(const char *str, char q);
int		is_special_character(char character);
void	signal_handler_sigquit(int sig);
void	change_exit_if_quit(t_ms **ms);
void	handle_tilde(char *input, int i, t_ms **ms);
char	*get_str_redi_out(char *cmd, t_ms **ms, char *str2, size_t *h);
char	*add_end(char *str, char *cmd);
void	signal_pipes(t_ms **ms);
void	signal_handler_pipes(int sig);
char	*remore_redir_eof(char *e_o_f);
void	add_tmp_var1(char *input, t_ms **ms);
void	pipe_mini(t_ms **ms);
void	add_to_empty2(char *(*empty)[52]);
void	add_to_empty(char *(*empty)[52]);
int		process_n_option(char **str_comp, int *i, t_check_option_n *opt);
int		check_option_n(char **str_comp, int *i, t_check_option_n opt);
char	*errors_with_quotes(char *input, t_ms **ms);
void	errors_with_quotes2(char *input, char **new_input, size_t *i, \
	size_t *j);
void	catch_errors(char *input, size_t *i);
void	init_envp_empty(t_ms **ms);
int		quotes3_1(char *input, size_t *i, int *error, int *found);
int		quotes3_2(char *input, size_t *i, int *found);
void	print_error_export(size_t *i, size_t l, char *input);
void	errors_with_quotes3_1(char *input, size_t *i, int *error, int *found);
int		errors_e_out(char **input_trim, t_ms **ms);
char	*trim_str_export(t_ms **ms);
char	*trim_str_export2(t_ms **ms, size_t h);
#endif