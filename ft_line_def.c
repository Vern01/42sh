/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_def.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 09:25:45 by vivan-de          #+#    #+#             */
/*   Updated: 2016/08/05 10:39:45 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

t_line	*ft_line_def()
{
	t_line	*l;

	if (!(l = (t_line *)malloc(sizeof(t_line))))
		exit(0);
	l->i = 0;
	l->cursor = 0;
	l->c = 'a';
	l->line = NULL;
	l->entered = NULL;
	l->prev = NULL;
	l->next = NULL;
	return (l);
}
