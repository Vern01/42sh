/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_pressed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 11:50:04 by vivan-de          #+#    #+#             */
/*   Updated: 2016/09/09 08:58:07 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static void	set_key(t_key *key)
{
	key->term = getenv("TERM");
	tgetent(key->buff, key->term);
	key->line = key->buff;
}

static void	ft_pick(char *s, t_line **l, t_key key)
{
	if (*s == 127 && (*l)->cursor > 0)
		ft_backspace(*l);
	else if (*s == 10)
		ft_putchar('\n');
	else if (*s == 27 && s[2] == 65)
		ft_arrow_up(l, key);
	else if (*s == 27 && s[2] == 66)
		ft_arrow_down(l, key);
	else if (*s == 27 && s[2] == 67 && (*l)->cursor < (size_t)(*l)->i)
		ft_arrow_right(*l);
	else if (*s == 27 && s[2] == 68 && (*l)->cursor > 0)
		ft_arrow_left(*l);
}

void		ft_key_pressed(char *s, t_line **l)
{
	int			keycode;
	int			i;
	t_key		key;

	set_key(&key);
	if (ft_isprint(*s))
	{
		tputs(tgetstr("im", &key.line), 1, ft_putchar_re);
		tputs(s, 1, ft_putchar_re);
		tputs(tgetstr("ei", &key.line), 1, ft_putchar_re);
	}
	else
	{
		i = -1;
		while (s[++i])
			keycode = s[i];
		ft_pick(s, l, key);
	}
}
