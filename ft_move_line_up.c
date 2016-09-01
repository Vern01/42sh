/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_line_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 16:39:12 by rojones           #+#    #+#             */
/*   Updated: 2016/08/06 16:46:04 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_move_line_up(char *line, size_t *cursor)
{
	size_t	col;

	col = (size_t)(tgetnum("co"));
	if (*cursor - col < 0)
		return ;
	(*cursor) -= col;
	if ((*cursor) < 3)
		(*cursor) = 3;
}
