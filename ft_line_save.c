/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_save.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 09:45:33 by vivan-de          #+#    #+#             */
/*   Updated: 2016/08/06 14:36:56 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

void	ft_free_last(t_line **l)
{
	t_line	**temp;

	temp = l;
	while ((*l)->next->next != NULL)
	{
		*temp = *l;
		*l = (*l)->next;
	}
	free((*l)->next->line);
	free((*l)->next);
	*l = *temp;
}

void	ft_line_save(t_line **l)
{
	t_line	*new;

	if ((*l)->next == NULL)
		return ;
	if (!(new = (t_line *)malloc(sizeof(t_line))))
		exit(0);
	new->i = (*l)->i;
	new->cursor = (*l)->i;
	new->c = 'a';
	if (!(new->line = (char *)malloc(ft_strlen((*l)->line) + 1)))
		exit(0);
	new->line = ft_strcpy(new->line, (*l)->line);
	new->entered = NULL;
	new->next = NULL;
	ft_free_last(l);
	new->prev = *l;
	(*l)->next = new;
	*l = (*l)->next;
}
