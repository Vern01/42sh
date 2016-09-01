/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 09:36:04 by vivan-de          #+#    #+#             */
/*   Updated: 2016/08/06 13:15:15 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

void	ft_line_add(t_line **l)
{
	t_line	*new;

	while ((*l)->next != NULL)
		*l = (*l)->next;
	if (!(new = (t_line *)malloc(sizeof(t_line))))
		exit(0);
	new->i = 0;
	new->cursor = 0;
	new->c = 'a';
	new->line = NULL;
	new->entered = NULL;
	new->prev = *l;
	new->next = NULL;
	(*l)->next = new;
	*l = (*l)->next;
}
