/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_cut_paste.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 13:48:44 by sasiedu           #+#    #+#             */
/*   Updated: 2016/09/09 16:25:50 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	select_mode(t_term **sh)
{
	int		ret;

	ret = 0;
	ft_bzero((*sh)->save, MAX_LEN);
	(*sh)->i = (*sh)->my_cur;
	while (ret != 1)
	{
		if (ret == 2)
			select_left(&(*sh));
		else if (ret == 3)
			select_right(&(*sh));
		ret = select_input(&(*sh));
	}
	ft_reset_screen(&(*sh), (*sh)->my_cur, 0, 0);
}

int		select_input(t_term **sh)
{
	char	buf[7];

	ft_bzero(buf, 7);
	read(0, buf, 6);
	(*sh)->j = 0;
	if (ft_strlen(buf) == 6 && buf[0] == 27 && buf[4] == 50 && buf[5] == RIGHT)
		return (1);
	if (ft_strlen(buf) == 3 && buf[0] == 27 && buf[2] == LEFT)
		return (2);
	if (ft_strlen(buf) == 3 && buf[0] == 27 && buf[2] == RIGHT)
		return (3);
	if (ft_strlen(buf) == 6 && buf[0] == 27 && buf[4] == 50 && buf[5] == 70)
		return (cut(&(*sh)));
	if (ft_strlen(buf) == 6 && buf[0] == 27 && buf[4] == 50 && buf[5] == 72)
		return (copy(&(*sh)));
	return (0);
}

void	select_right(t_term **sh)
{
	if ((*sh)->std_cur < tgetnum("co") && (*sh)->my_cur < (*sh)->len)
	{
		tputs(tgetstr("dc", 0), 0, ft_shell_putchar);
		tputs(tgetstr("so", 0), 0, ft_shell_putchar);
		tputs(tgetstr("im", 0), 0, ft_shell_putchar);
		ft_putchar((*sh)->line[(*sh)->my_cur]);
		tputs(tgetstr("se", 0), 0, ft_shell_putchar);
		tputs(tgetstr("ei", 0), 0, ft_shell_putchar);
		(*sh)->std_cur++;
		(*sh)->my_cur++;
	}
}

void	select_left(t_term **sh)
{
	if ((*sh)->my_cur > (*sh)->i && (*sh)->std_cur > 0)
	{
		tputs(tgetstr("le", 0), 0, ft_shell_putchar);
		tputs(tgetstr("dc", 0), 0, ft_shell_putchar);
		tputs(tgetstr("im", 0), 0, ft_shell_putchar);
		ft_putchar((*sh)->line[(*sh)->my_cur - 1]);
		tputs(tgetstr("ei", 0), 0, ft_shell_putchar);
		tputs(tgetstr("le", 0), 0, ft_shell_putchar);
		(*sh)->std_cur--;
		(*sh)->my_cur--;
	}
}
