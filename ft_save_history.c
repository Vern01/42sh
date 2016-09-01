/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/03 09:27:13 by vivan-de          #+#    #+#             */
/*   Updated: 2016/08/04 09:31:19 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

t_line	*ft_save_history(t_line *l)
{
	t_line	*temp;
	t_line	*new;

	temp = l;
	while (temp != NULL && temp->next != NULL)
		temp = temp->next;
	if (!(new = (t_line *)malloc(sizeof(t_line))))
		exit(0);
	new->prev = temp;
	new->next = NULL;
	new->line = NULL;
	if (temp == NULL)
		return (new);
	temp->next = new;
	return (temp->next);
}
