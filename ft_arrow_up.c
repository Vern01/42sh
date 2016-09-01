/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrow_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 12:26:56 by vivan-de          #+#    #+#             */
/*   Updated: 2016/08/06 16:03:59 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

void	ft_arrow_up(t_line **l, t_key key)
{
	if ((*l)->prev != NULL)
	{
		ft_clean_line(*l, key);
		*l = (*l)->prev;
		tputs(tgetstr("im", &key.line), 1, ft_putchar_re);
		tputs((*l)->line, 1, ft_putchar_re);
		tputs(tgetstr("ei", &key.line), 1, ft_putchar_re);
	}
}
