/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 14:48:38 by rojones           #+#    #+#             */
/*   Updated: 2016/09/09 08:56:31 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

void	ft_init_win(t_win *win)
{
	char	*buf;

	buf = NULL;
	tgetent(buf, getenv("TERM"));
	if (!isatty(STDOUT_FILENO))
		return ;
	else
	{
		if (tcgetattr(0, &win->owin) != 0)
			ft_putstr_fd("error taking over terminal\n", 2);
		if (tcgetattr(0, &win->nwin) != 0)
			ft_putstr_fd("error taking over terminal\n", 2);
		else
		{
			win->nwin.c_iflag |= IGNBRK;
			win->nwin.c_lflag |= ISIG;
			win->nwin.c_lflag &= ~(ICANON | ECHO);
			win->nwin.c_cc[VMIN] = 1;
			win->nwin.c_cc[VTIME] = 0;
			tcsetattr(0, TCSANOW, &win->nwin);
		}
	}
}
