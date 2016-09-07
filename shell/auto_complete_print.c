/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_complete_print.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 10:40:39 by sasiedu           #+#    #+#             */
/*   Updated: 2016/09/07 13:49:37 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	auto_complete_print(t_list *lst, t_auto *new, int h, int cur)
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	h += 1;
	i = -1;
	tputs(tgetstr("do", 0), 0, ft_shell_putchar);
	tputs(tgetstr("cd", 0), 0, ft_shell_putchar);
	while (tmp != NULL && ++i < new->nb)
	{
		tputs(tgetstr("cr", 0), 0, ft_shell_putchar);
		tputs(tgoto(tgetstr("RI", 0), 0, (new->len + 3) * i), 0, \
				ft_shell_putchar);
		auto_putstr(tmp->content, tmp->content_size);
		tmp = tmp->next;
	}
	if (tmp != NULL)
		auto_complete_print(tmp, new, h, cur);
	else
		return (auto_move_cursor(h, cur % tgetnum("co")));
}

void	auto_move_cursor(int h, int w)
{
	int		y;
	int		x;

	y = -1;
	while (++y < h)
		tputs(tgetstr("up", 0), 0, ft_shell_putchar);
	tputs(tgetstr("cr", 0), 0, ft_shell_putchar);
	x = -1;
	while (++x < w)
		tputs(tgetstr("nd", 0), 0, ft_shell_putchar);
}

void	auto_putstr(char *line, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
		ft_putchar(line[i]);
}
