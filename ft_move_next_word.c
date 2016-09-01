/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_next_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 09:09:35 by rojones           #+#    #+#             */
/*   Updated: 2016/08/06 09:15:31 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

void	ft_move_next_word(char *line, size_t *cursor)
{
	if (line == NULL)
		return ;
	while (line[*cursor] && ft_isspace(line[*cursor]) == 0)
		(*cursor)++;
	if (line[*cursor])
		(*cursor)++;
}
