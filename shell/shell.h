/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 21:24:05 by sasiedu           #+#    #+#             */
/*   Updated: 2016/09/07 14:40:52 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "../libft/libft.h"
# include "../ft_sh21.h"
# include <term.h>
# include <curses.h>
# include <sys/ioctl.h>

# define USER "$> "
# define OTH "$> "
# define WORD " 	"
# define TRUE 1
# define FLASE 0
# define MAX_LEN 1024
# define ENTER 10
# define BKSPC 127
# define WORD_LONG "error: line exceeds 256 bytes. Max lenght reached\n"

/*
*** TERMCAPS DEFINITIONS USED
*** "nd": move right one, "le": move left one, "cd": remove lines && ff lines
*** "cl": to clear screen, "co": scree wid, "cr": move to margin
*** "dl": to del line, "do": move down one, "DO": move down more
*** "ho": move top left, "LE":move lfet more, "lm": total lines in terminal
*** "rc": move to save position, "RI": move right more, "sc": save position
*** "uc": underline & move right, "ue": underline off, "up": move up one
*** "UP": move up more, "us": underline on, "vb": screen flash, "cm":move x y
*/

/*
*** COMBINE ASCII VALUE
*/
# define UP 65
# define DOWN 66
# define LEFT 68
# define RIGHT 67
# define HOME 72
# define END 70
# define SHIFT 50

typedef	struct	s_term
{
	int			nb_lines;
	int			my_cur;
	int			std_cur;
	int			my_h;
	int			len;
	int			std_usr;
	char		*prt;
	char		buf[3];
	char		*line;
	char		*save;
	char		*current;
}				t_term;

typedef	struct	s_auto
{
	int			nb;
	int			len;
}				t_auto;

/*
***  shell main fucntions
*/
t_term			*ft_init_shell(void);
char			*get_line(char *line);
int				ft_read_entry(t_term **sh);
int				ft_buf_input(t_term **sh);

/*
*** keys functions
*/
int				ft_single_ascii(t_term **sh);
int				ft_combine_ascii(t_term **sh);
int				ft_enter_key(t_term **sh, int tmp, int i);
int				ft_special_key(t_term **sh);
void			ft_add_to_line(t_term **sh);
void			ft_remove_from_line(t_term **sh);
void			ft_home_key(t_term **sh);
void			ft_end_key(t_term **sh);
void			ft_clear_screen(t_term **sh);

/*
*** line utils functions
*/
int				ft_add_char_line(char **line, const char c, \
		int pos, int *size);
int				ft_remove_char_line(char **line, int pos, int *size);
void			ft_reset_screen(t_term **sh, int cur_pos, int w, int tmp);
void			ft_move_cursor_right(int tmp);
void			ft_move_cursor_left(int tmp);
void			ft_check_quotes(char *line, t_term **sh, int i);
void			ft_move_home_word(t_term **sh, char *line, int i, int j);

/*
*** history functions
*** UP is a rule for getting up history
*** DOWN is a rule for getting down history
*** "reset" is a rule for adding line to history
*/
char			*ft_history_tower(char *access, char *line);
char			*ft_history_line(t_list **lst, int ptr);

/*
*** arrow keys
*/
void			ft_up_key(t_term **sh);
void			ft_down_key(t_term **sh);
void			ft_left_key(t_term **sh);
void			ft_right_key(t_term **sh);

/*
*** ctrl keys
*/
int				ft_ctrl_key(t_term **sh);
int				next_word(char *line, int i);
int				prev_word(char *line, int i);
void			ft_ctrl_home_key(t_term **sh, char *line, int i, int j);
void			ft_ctrl_end_key(t_term **sh, char *line);

/*
*** extra functions
*/
struct termios	ft_echo_off(int fd);
size_t			ft_lstsize(t_list *lst);
int				ft_shell_putchar(int c);
void			ft_exec_quotes(t_term **sh);

/*
*** auto complete
*/
t_list			*get_auto_list(t_term **sh, t_auto *new, char *line);
t_list			*auto_read_bin(t_list *lst, t_auto *new, char *line, int ret);
t_list			*auto_read_dir(t_list *lst, t_auto *new, char *line, int ret);
int				check_auto(char *line);
int				ft_auto(t_term **sh);
char			*get_auto_line(char *line);
int				ft_auto_complete(t_term **sh, t_list *lst, t_list *tmp, \
		int ret);
void			auto_complete_print(t_list *lst, t_auto *new, int h, int cur);
void			auto_move_cursor(int h, int w);
void			auto_putstr(char *line, size_t size);

#endif
