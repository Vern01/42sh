/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 06:58:26 by oexall            #+#    #+#             */
/*   Updated: 2016/08/30 07:21:21 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

void	ft_init_termcap(t_win *win)
{
	if (tgetent(NULL, getenv("TERM")) < 1)
		return ;
	if (tcgetattr(0, &win->term) == -1)
		return ;
	win->term.c_lflag &= ~(ICANON | ECHO);
	win->term.c_cc[VMIN] = 1;
	win->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &win->term) == -1)
		return ;
}

void	ft_end_termcap(t_win *win)
{
	win->term.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, TCSANOW, &win->term) == -1)
		return ;
}