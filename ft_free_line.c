/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 17:41:31 by rojones           #+#    #+#             */
/*   Updated: 2016/08/06 17:50:14 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

void	ft_free_line(t_line *line)
{
	t_line	*mv;
	t_line	*mv2;

	mv = line;
	while (mv->prev)
		mv = mv->prev;
	while (mv)
	{
		mv2 = mv->next;
		if (mv->line)
			free(mv->line);
		if (mv->entered)
			free(mv->entered);
		free(mv);
		mv = mv2;
	}
}
