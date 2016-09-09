/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_shift.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 12:40:39 by sasiedu           #+#    #+#             */
/*   Updated: 2016/09/09 14:43:22 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_shift_key(t_term **sh)
{
	if ((*sh)->buf[2] == UP)
		ft_shift_up_down(&(*sh), 1);
	else if ((*sh)->buf[2] == DOWN)
		ft_shift_up_down(&(*sh), 2);
	else if ((*sh)->buf[2] == RIGHT)
		select_mode(&(*sh));
}

void	ft_shift_up_down(t_term **sh, int index)
{
	if ((*sh)->my_h > 0 && index == 1)
	{
		tputs(tgetstr("up", 0), 0, ft_shell_putchar);
		(*sh)->my_cur = (*sh)->my_cur - tgetnum("co");
		(*sh)->my_h--;
		tputs(tgetstr("cr", 0), 0, ft_shell_putchar);
		(*sh)->std_cur = (*sh)->std_cur % tgetnum("co");
		ft_move_cursor_right((*sh)->std_cur);
	}
	if ((*sh)->my_h < (*sh)->nb_lines && index == 2)
	{
		tputs(tgetstr("do", 0), 0, ft_shell_putchar);
		(*sh)->my_cur = (*sh)->my_cur + tgetnum("co");
		if ((*sh)->my_cur >= (*sh)->len)
			(*sh)->my_cur = (*sh)->len;
		(*sh)->my_h++;
		tputs(tgetstr("cr", 0), 0, ft_shell_putchar);
		(*sh)->std_cur = (*sh)->std_cur % tgetnum("co");
		ft_move_cursor_right((*sh)->std_cur);
	}
}
