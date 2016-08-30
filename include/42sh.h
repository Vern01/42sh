/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 11:38:21 by oexall            #+#    #+#             */
/*   Updated: 2016/08/30 08:01:10 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _42SH_H_
# define _42SH_H_

# include <libft.h>
# include <errors.h>
# include <termcap.h>
# include <termios.h>

typedef struct		s_win
{
	struct termios	term;
}					t_win;

typedef struct		s_env
{
	char			**environ;
	t_win			win;
}					t_env;

/*
** Other common functions
*/
int					ft_error(int ret, char *cmd, char *err);

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
int					ft_setenv(t_env *env, char *name, char *value, int reset);

/*
** Initialization of termcaps and associated commands
*/
void				ft_init_termcap(t_win *win);
void				ft_end_termcap(t_win *win);
#endif
