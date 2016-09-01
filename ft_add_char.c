/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 12:16:25 by vivan-de          #+#    #+#             */
/*   Updated: 2016/08/06 17:39:01 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

void	ft_add_char(t_line *l)
{
	char	*temp;
	int		i;
	int		j;

	temp = l->line;
	if (!(l->line = (char *)malloc(sizeof(char) * (l->i + 1))))
		exit(0);
	i = 0;
	j = 0;
	while (i < (l->i + 1))
	{
		if ((size_t)i == l->cursor)
			l->line[i] = l->c;
		else
			l->line[i] = temp[j++];
		i++;
	}
	l->line[i] = '\0';
	free(temp);
	l->cursor++;
}
