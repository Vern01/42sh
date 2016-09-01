/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrow_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 14:13:14 by vivan-de          #+#    #+#             */
/*   Updated: 2016/08/04 10:09:46 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

void	ft_arrow_left(t_line *l)
{
	char	*line;
	char	buff[2048];
	char	*term;

	term = getenv("TERM");
	tgetent(buff, term);
	line = buff;
	tputs(tgetstr("le", &line), 1, ft_putchar_re);
	l->cursor -= 1;
}
