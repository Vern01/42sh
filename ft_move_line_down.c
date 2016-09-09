/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_line_down.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 16:46:26 by rojones           #+#    #+#             */
/*   Updated: 2016/09/09 09:26:08 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

void	ft_move_line_down(char *line, size_t *cursor)
{
	size_t	col;

	col = (size_t)(tgetnum("co"));
	if (((*cursor) % col == (size_t)(ft_strlen(line)) % col))
		return ;
	(*cursor) += col;
	if ((*cursor) > (size_t)(ft_strlen(line)))
		(*cursor) = (size_t)(ft_strlen(line));
}
