/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backspace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 17:31:13 by vivan-de          #+#    #+#             */
/*   Updated: 2016/08/06 16:35:52 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

void	ft_backspace(void)
{
	char	*line;
	char	buff[1024];
	char	*term;

	term = getenv("TERM");
	tgetent(buff, term);
	line = buff;
	tputs(tgetstr("smir", &line), 1, ft_putchar_re);
	tputs(tgetstr("le", &line), 1, ft_putchar_re);
	tputs(tgetstr("dm", &line), 1, ft_putchar_re);
	tputs(tgetstr("dc", &line), 1, ft_putchar_re);
	tputs(tgetstr("ed", &line), 1, ft_putchar_re);
	tputs(tgetstr("rmir", &line), 1, ft_putchar_re);
}
