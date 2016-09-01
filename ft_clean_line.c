/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 16:00:34 by rojones           #+#    #+#             */
/*   Updated: 2016/08/06 16:03:13 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

void	ft_clean_line(t_line *l, t_key key)
{
	int		n;

	n = 0;
	while (n++ < l->i)
		tputs(tgetstr("le", &key.line), 1, ft_putchar_re);
	tputs(tgetstr("ce", &key.line), 1, ft_putchar_re);
}
