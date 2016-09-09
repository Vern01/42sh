# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rojones <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/28 08:54:36 by rojones           #+#    #+#              #
#    Updated: 2016/09/09 10:47:55 by rojones          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh
CCFLAGS = gcc -Wall -Werror -Wextra -g3
OBJ = ft_add_char.o ft_arglen.o ft_arrow_down.o ft_arrow_left.o ft_arrow_right.o ft_arrow_up.o\
	  ft_backspace.o ft_build_env_var.o ft_cd.o ft_cd_home.o ft_clean_line.o\
	  ft_cd_opwd.o ft_check_arg_case_len.o ft_check_arg_op.o ft_check_dir.o \
	  ft_check_env_var.o ft_check_redir_files.o ft_count_arg.o ft_cpyenv.o \
	  ft_echo.o ft_echo_env_var.o ft_echo_str.o ft_env.o ft_echo_case.o \
	  ft_exc_cd.o ft_exe_path.o ft_exit.o ft_extract_arg.o ft_extract_args.o \
	  ft_extract_redir.o ft_free_line.o ft_get_comm.o ft_get_env_var.o \
	  ft_get_next_line.o \
	  ft_get_qut.o ft_get_redir.o ft_init_win.o ft_isop.o ft_key_pressed.o\
	  ft_launch.o ft_line_add.o ft_line_def.o ft_line_save.o \
	  ft_lines_entered.o ft_loop_redir_out.o\
	  ft_pwd_var.o ft_next_op.o ft_num_args.o ft_redir_in.o ft_redir_out.o \
	  ft_redir_over.o ft_rem_args.o ft_remove_char.o ft_restor_win.o \
	  ft_split_arg_op.o ft_run_script.o\
	  ft_split_line_op.o ft_split_redir.o ft_search_path.o \
	  ft_setenv.o ft_skip_spaces.o ft_split_input.o ft_str_qut_char.o \
	  ft_trunc_args.o ft_unsetenv.o ft_update_env_pwd.o ft_local_export.o \
	  ft_local_unset.o

OBJ2 = shell/history.o shell/keys.o shell/keys_arrow.o shell/keys_ctrl.o \
	   shell/keys_extra.o shell/keys_line.o shell/line_utils.o \
	   shell/new_main.o shell/quotes.o shell/tools.o shell/shell_main.o \
	   shell/auto_complete.o shell/auto_complete_tools.o shell/ft_lstsize.o\
	   shell/auto_complete_read.o shell/auto_complete_print.o \
	   shell/keys_ctrl_tools.c

MAKELIB = make -C libft
MAKELIBCLEAN = make -C libft clean

$(NAME) : $(OBJ)
	$(MAKELIB)
	@make -C shell/
	$(CCFLAGS) -lcurses -Llibft -lft -o $(NAME) ft_sh21.c $(OBJ) $(OBJ2)

all : $(NAME)

clean :
	@make -C shell/ clean
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all

ft_add_char.o : ft_add_char.c
	$(CCFLAGS) -c ft_add_char.c

ft_arglen.o : ft_arglen.c
	$(CCFLAGS) -c ft_arglen.c

ft_arrow_down.o : ft_arrow_down.c
	$(CCFLAGS) -c ft_arrow_down.c
ft_arrow_left.o : ft_arrow_left.c
	$(CCFLAGS) -c ft_arrow_left.c

ft_arrow_right.o : ft_arrow_right.c
	$(CCFLAGS) -c ft_arrow_right.c

ft_arrow_up.o : ft_arrow_up.c
	$(CCFLAGS) -c ft_arrow_up.c

ft_backspace.o : ft_backspace.c
	$(CCFLAGS) -c ft_backspace.c

ft_build_env_var.o : ft_build_env_var.c
	$(CCFLAGS) -c ft_build_env_var.c

ft_cd.o : ft_cd.c
	$(CCFLAGS) -c ft_cd.c

ft_cd_home.o : ft_cd_home.c
	$(CCFLAGS) -c ft_cd_home.c

ft_cd_opwd.o : ft_cd_opwd.c
	$(CCFLAGS) -c ft_cd_opwd.c

ft_check_arg_case_len.o : ft_check_arg_case_len.c
	$(CCFLAGS) -c ft_check_arg_case_len.c

ft_check_arg_op.o : ft_check_arg_op.c
	$(CCFLAGS) -c ft_check_arg_op.c

ft_check_dir.o : ft_check_dir.c
	$(CCFLAGS) -c ft_check_dir.c

ft_check_env_var.o : ft_check_env_var.c
	$(CCFLAGS) -c ft_check_env_var.c

ft_check_redir_files.o : ft_check_redir_files.c
	$(CCFLAGS) -c ft_check_redir_files.c

ft_clean_line.o : ft_clean_line.c
	$(CCFLAGS) -c ft_clean_line.c

ft_count_arg.o : ft_count_arg.c
	$(CCFLAGS) -c ft_count_arg.c

ft_cpyenv.o : ft_cpyenv.c
	$(CCFLAGS) -c ft_cpyenv.c

ft_echo.o : ft_echo.c
	$(CCFLAGS) -c ft_echo.c

ft_echo_env_var.o : ft_echo_env_var.c
	$(CCFLAGS) -c ft_echo_env_var.c

ft_echo_str.o : ft_echo_str.c
	$(CCFLAGS) -c ft_echo_str.c

ft_echo_case.o : ft_echo_case.c
	$(CCFLAGS) -c ft_echo_case.c

ft_env.o : ft_env.c
	$(CCFLAGS) -c ft_env.c

ft_exc_cd.o : ft_exc_cd.c
	$(CCFLAGS) -c ft_exc_cd.c

ft_exe_path.o : ft_exe_path.c
	$(CCFLAGS) -c ft_exe_path.c

ft_exit.o : ft_exit.c
	$(CCFLAGS) -c ft_exit.c

ft_extract_arg.o : ft_extract_arg.c
	$(CCFLAGS) -c ft_extract_arg.c

ft_extract_args.o : ft_extract_args.c
	$(CCFLAGS) -c ft_extract_args.c

ft_extract_redir.o : ft_extract_redir.c
	$(CCFLAGS) -c ft_extract_redir.c

ft_free_str_arr.o : ft_free_str_arr.c
	$(CCFLAGS) -c ft_free_str_arr.c

ft_key_pressed.o : ft_key_pressed.c
	$(CCFLAGS) -c ft_key_pressed.c

ft_launch.o : ft_launch.c
	$(CCFLAGS) -c ft_launch.c

ft_line_add.o : ft_line_add.c
	$(CCFLAGS) -c ft_line_add.c

ft_line_def.o : ft_line_def.c
	$(CCFLAGS) -c ft_line_def.c

ft_line_save.o : ft_line_save.c
	$(CCFLAGS) -c ft_line_save.c

ft_lines_entered.o : ft_lines_entered.c
	$(CCFLAGS) -c ft_lines_entered.c

ft_loop_redir_out.o : ft_loop_redir_out.c
	$(CCFLAGS) -c ft_loop_redir_out.c

ft_next_op.o : ft_next_op.c
	$(CCFLAGS) -c ft_next_op.c

ft_num_args.o : ft_num_args.c
	$(CCFLAGS) -c ft_num_args.c

ft_pwd_var.o : ft_pwd_var.c
	$(CCFLAGS) -c ft_pwd_var.c

ft_free_line.o : ft_free_line.c
	$(CCFLAGS) -c ft_free_line.c

ft_get_comm.o : ft_get_comm.c
	$(CCFLAGS) -c ft_get_comm.c

ft_get_env_var.o : ft_get_env_var.c
	$(CCFLAGS) -c ft_get_env_var.c

ft_get_next_line.o : ft_get_next_line.c
	$(CCFLAGS) -c ft_get_next_line.c

ft_get_qut.o : ft_get_qut.c
	$(CCFLAGS) -c ft_get_qut.c

ft_get_redir.o : ft_get_redir.c
	$(CCFLAGS) -c ft_get_redir.c

ft_get_op_type.o : ft_get_op_type.c
	$(CCFLAGS) -c ft_get_op_type.c

ft_init_win.o : ft_init_win.c
	$(CCFLAGS) -c ft_init_win.c

ft_isop.o : ft_isop.c
	$(CCFLAGS) -c ft_isop.c

ft_redir_in.o : ft_redir_in.c
	$(CCFLAGS) -c ft_redir_in.c

ft_redir_out.o : ft_redir_out.c
	$(CCFLAGS) -c ft_redir_out.c

ft_rem_args.o : ft_rem_args.c
	$(CCFLAGS) -c ft_rem_args.c

ft_remove_char.o : ft_remove_char.c
	$(CCFLAGS) -c ft_remove_char.c

ft_redir_over.o : ft_redir_over.c
	$(CCFLAGS) -c ft_redir_over.c

ft_restor_win.o : ft_restor_win.c
	$(CCFLAGS) -c ft_restor_win.c

ft_run_script.o : ft_run_script.c
	$(CCFLAGS) -c ft_run_script.c 

ft_search_path.o : ft_search_path.c
	$(CCFLAGS) -c ft_search_path.c

ft_setenv.o : ft_setenv.c
	$(CCFLAGS) -c ft_setenv.c

ft_skip_spaces.o : ft_skip_spaces.c
	$(CCFLAGS) -c ft_skip_spaces.c

ft_split_arg_op.o : ft_split_arg_op.c
	$(CCFLAGS) -c ft_split_arg_op.c

ft_split_line_op.o : ft_split_line_op.c
	$(CCFLAGS) -c ft_split_line_op.c

ft_split_input.o : ft_split_input.c
	$(CCFLAGS) -c ft_split_input.c

ft_split_redir.o : ft_split_redir.c
	$(CCFLAGS) -c ft_split_redir.c

ft_str_qut_char.o : ft_str_qut_char.c
	$(CCFLAGS) -c ft_str_qut_char.c

ft_trunc_args.o : ft_trunc_args.c
	$(CCFLAGS) -c ft_trunc_args.c

ft_unsetenv.o : ft_unsetenv.c
	$(CCFLAGS) -c ft_unsetenv.c

ft_update_env_pwd.o : ft_update_env_pwd.c
	$(CCFLAGS) -c ft_update_env_pwd.c

ft_local_export.o : ft_local_export.c
	$(CCFLAGS) -c ft_local_export.c

ft_local_unset.o : ft_local_unset.c
	$(CCFLAGS) -c ft_local_unset.c
