/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 08:48:05 by rojones           #+#    #+#             */
/*   Updated: 2016/09/06 13:25:57 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H
# include "libft/libft.h"
# include <dirent.h>
# include <termios.h>
# include <curses.h>
# include <term.h>


typedef struct	s_win
{
	struct termios nwin;
	struct termios owin;
}				t_win;

typedef struct	s_getredir
{
	int     i;  
	int     j;  
	int     s_qut;
	int     d_qut;
	char    *temp;
	char    *temp2;
	char    *temp3;
	char    *temp4;
	char    *templine1;
	char    *templine2;
}				t_getredir;

typedef struct	s_launch
{
	pid_t   pid;
	int     i;  
	int     fd_in;
	int     p[2];
	char    **args;
	char    **splredir;
	char    **cmd;
	char    *redir;
	char    **out;
	char    **in;
}				t_launch;

typedef struct	s_echo_flag
{
	int	n;
	int	set_e;
}				t_echo_flag;

typedef struct	s_pipe_redir
{
	int	re;
	int	pipe;
	int	reapp;
}				t_pipe_redir;

typedef struct          s_line
{
	int             i;  
	size_t          cursor;
	char            c;  
	char            *line;
	char            *entered;
	struct s_line   *prev;
	struct s_line   *next;
}                       t_line;

typedef struct              s_key
{
	char                *line;
	char                buff[2048];
	char                *term;
}                           t_key;

typedef struct	s_data
{
	t_win	win;
	t_line	*line;
	char	**env;
	char	**local;
}				t_data;

void			ft_add_char(t_line *l);
int				ft_arglen(char *s, int *start);
void			ft_arrow_down(t_line **l, t_key key);
void			ft_arrow_left(t_line *l);
void			ft_arrow_right(t_line *l);
void			ft_arrow_up(t_line **l, t_key key);
void			ft_backspace();
char			*ft_build_env_var(char **split);
char			**ft_cd(char **args, t_data *data);
void			ft_cd_home(t_data *data);
void			ft_cd_opwd(t_data *data);
int				ft_check_arg_op(char *str);
void			ft_check_arg_case_len(char *line, int *s_qut, int *d_qut, int *i);
int				ft_check_dir(char *path, char *name);
int				ft_check_env_var(char *arg, char **env);
char			*ft_check_qut(char *line);
void			ft_check_redir_files(char *line);
void			ft_clean_line(t_line *l, t_key key);
int				ft_count_arg(char **args);
char			**ft_cpyenv(char **env);
void			ft_echo(char **args, char **env);
char			ft_echo_case(char *str, int *i);
int				ft_echo_env_var(char **env, char *arg);
int				ft_echo_str(char *str);
void			ft_exc_cd(char *path, char **env);
int				ft_exe_path(char **args, t_data *data);
void			ft_exit(char **split, t_data *data);
char			**ft_extract_args(char *line);
char			*ft_extract_arg(int len, int start, int *end, char *line);
char			*ft_extract_redir(char **line, char *redir, int st, int end);
void			ft_env(char **split, char **env);
void			ft_free_line(t_line *line);
char			**ft_get_comm(char **args, t_data *data);
char			*ft_get_env_var(char **env, int ind);
int				ft_get_next_line(int const fd, t_line **l);
char			*ft_get_redir(char **line);
int				ft_isop(char c);
void			ft_init_win(t_win *win);
void			ft_key_pressed(char *s, t_line **l);
char			**ft_launch(char *line, t_data *data);
void			ft_line_add(t_line **l);
t_line			*ft_line_def();
void			ft_line_save(t_line **l);
void			ft_lines_entered(t_line **l);
char			**ft_loop_redir_out(t_launch *lau, t_data *data, char **env,
				int i);
int				ft_next_op(char **args);
int				ft_num_args(char *s);
char			**ft_op_order(char **args, char **env);
char			*ft_pwd_var(char *pwd, char *value);
int				ft_redir_in(char *redir, int cl, int init);
int				ft_redir_out(char *redir, int cl);
int				ft_redir_over(char *redir, char *op);
char			**ft_rem_args(char **args);
void			ft_remove_char(t_line *l);
void			ft_restor_win(t_win *win);
char			*ft_search_path(char **args, t_data *data);
char			**ft_setenv(char **split, t_data *data);
void			ft_skip_space(char *line, int *i);
char			***ft_split_arg_op(char **args);
char			**ft_split_line_op(char *line);
char			**ft_split_input(char *line, t_data *data);
void			ft_split_redir(char **redir, char ***out, char ***in);
char			*ft_str_qut_char(char *str, char c);
char			*ft_sub_arg(char *line, int start, int end);
char			**ft_trunc_args(char **args);
char			**ft_unsetenv(char **split, t_data *data);
void			ft_update_pwd_env(char **env, char **value, int i);
#endif
