/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 09:36:51 by vivan-de          #+#    #+#             */
/*   Updated: 2016/08/04 08:41:19 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

void	ft_remove_char(t_line *l)
{
	char	*temp;
	size_t	i;
	size_t	j;

	temp = l->line;
//	ft_putstr("\n#");
//	ft_putstr(l->temp);
//	ft_putstr("#\n");
	l->i--;
	l->cursor--;
	if (!(l->line = (char *)malloc(sizeof(char *) * (l->i + 1))))
		exit(0);
	i = 0;
	j = 0;
//	ft_putnbr(l->i);
	while (i < (size_t)l->i + 1)
	{
		if (i == l->cursor)
			j++;
		l->line[i] = temp[j++];
		i++;
	}
	l->line[l->i] = '\0';
//	ft_putstr("\n#");
//	ft_putstr(l->temp);
//	ft_putstr("#\n");
	free(temp);
//	l->cursor--;
}
