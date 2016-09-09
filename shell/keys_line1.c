/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_line1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 09:59:53 by sasiedu           #+#    #+#             */
/*   Updated: 2016/09/09 16:31:40 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_reset_screen2(t_term **sh, int cur_pos, int w, int tmp)
{
	w = tgetnum("co");
	(*sh)->my_h = (ft_strlen((*sh)->prt) + cur_pos) / w;
	(*sh)->nb_lines = (ft_strlen((*sh)->prt) + (*sh)->len) / w;
	tputs(tgetstr("rc", 0), 0, ft_shell_putchar);
	tputs(tgetstr("cd", 0), 0, ft_shell_putchar);
	tputs(tgetstr("cr", 0), 0, ft_shell_putchar);
	ft_putstr((*sh)->prt);
	tputs((*sh)->line, 0, ft_shell_putchar);
	tputs(tgetstr("rc", 0), 0, ft_shell_putchar);
	tmp = (*sh)->my_h;
	while (tmp-- > 0)
		tputs(tgetstr("do", 0), 0, ft_shell_putchar);
	tputs(tgetstr("cr", 0), 0, ft_shell_putchar);
	(*sh)->std_cur = (*sh)->std_cur % w;
	ft_move_cursor_right((*sh)->std_cur);
}

void	get_new_cursor_position(t_term **sh, int width)
{
	int		h;

	h = (ft_strlen((*sh)->prt) + (*sh)->len - 1) / width;
	tputs(tgetstr("cr", 0), 0, ft_shell_putchar);
	while (h-- > 0)
		tputs(tgetstr("up", 0), 0, ft_shell_putchar);
	tputs(tgetstr("sc", 0), 0, ft_shell_putchar);
}
