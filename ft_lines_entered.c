/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lines_entered.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 10:22:23 by vivan-de          #+#    #+#             */
/*   Updated: 2016/08/06 13:12:33 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

void	ft_lines_entered(t_line **l)
{
	t_line	*temp;

	while ((*l)->next != NULL)
		*l = (*l)->next;
	temp = *l;
	if ((*l)->entered == NULL && (*l)->line != NULL)
	{
		if (!((*l)->entered = (char *)malloc((ft_strlen((*l)->line) + 1))))
			exit(0);
		(*l)->entered = ft_strcpy((*l)->entered, (*l)->line);
	}
	while ((*l)->prev != NULL)
	{
		free((*l)->line);
		if (!((*l)->line = (char *)malloc(ft_strlen((*l)->entered) + 1)))
			exit(0);
		(*l)->line = ft_strcpy((*l)->line, (*l)->entered);
		(*l) = (*l)->prev;
	}
	if (!((*l)->line = (char *)malloc(ft_strlen((*l)->entered) + 1)))
		exit(0);
	(*l)->line = ft_strcpy((*l)->line, (*l)->entered);
	*l = temp;
}
