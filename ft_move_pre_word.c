/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_pre_word.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 08:58:30 by rojones           #+#    #+#             */
/*   Updated: 2016/08/06 14:11:45 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static void	ft_skip_space_back(char *line, size_t *cursor)
{
	while (*cursor > 0 && ft_isspace(line[*cursor]) == 1)
		(*cursor)--;
}

void		ft_move_pre_word(char *line, size_t *cursor)
{
	int found;

	found = 0;
	if (ft_isspace(line[*cursor]) == 1)
		ft_skip_space_back(line, cursor);
	else if ((*cursor) - 1 > 0 && (ft_isspace(line[(*cursor) - 1]) == 1))
	{
		(*cursor)--;
		ft_skip_space_back(line, cursor);
	}
	while (*cursor > 0 && found == 0)
	{
		if (ft_isspace(line[*cursor]) == 1)
			found = 1;
		else
			(*cursor)--;
	}
	if (found == 1)
		(*cursor)++;
}
