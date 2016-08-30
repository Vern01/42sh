/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 11:38:21 by oexall            #+#    #+#             */
/*   Updated: 2016/08/30 10:33:00 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _42SH_H_
# define _42SH_H_

# include <libft.h>
# include <errors.h>
# include <termcap.h>
# include <termios.h>

typedef struct		s_line
{
	int				i;
	size_t			cursor;
	char			c;
	char			*line;
	char			*entered;
	struct s_line	*next;
	struct s_line	*prev;
}					t_line;

typedef struct		s_win
{
	struct termios	oterm;
	struct termios	term;
}					t_win;

typedef struct		s_env
{
	char			**environ;
	t_line			*line;
	t_win			win;
}					t_env;

/*
** Other common functions
*/
int					ft_error(int ret, char *cmd, char *err);
int					ft_cargs(char **tab);
char				*ft_chrjoin(char *str1, char *str2, char c);

/*
**Main functions
*/
int					ft_loop(t_env *env);

/*
**	Reading & Changing of the Enviroment Variables
*/
void				ft_read_environ(t_env *env, char **environ);
void				ft_free_environ(char **environ);
void				ft_print_env(t_env *env);
char				*ft_getenv(char *name, t_env *env);
char				**ft_dupenviron(char **environ, int size);
int					ft_setenv(t_env *env, char *name, char *value, int reset);
int					ft_update_env(t_env *env, char *name, char *value);
int					ft_unsetenv(t_env *env, char *name);

/*
** Initialization of termcaps and associated commands
*/
void				ft_init_termcap(t_win *win);
void				ft_end_termcap(t_win *win);
#endif
