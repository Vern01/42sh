/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrow_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 14:13:14 by vivan-de          #+#    #+#             */
/*   Updated: 2016/08/06 16:36:02 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

void	ft_arrow_right(t_line *l)
{
	char	*line;
	char	buff[2048];
	char	*term;

	term = getenv("TERM");
	tgetent(buff, term);
	line = buff;
	if (l->cursor == (size_t)tgetnum("co") - 3)
		tputs(tgetstr("do", &line), 1, ft_putchar_re);
	tputs(tgetstr("nd", &line), 1, ft_putchar_re);
	l->cursor += 1;
}
