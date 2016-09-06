/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_qut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 15:42:59 by rojones           #+#    #+#             */
/*   Updated: 2016/09/01 12:51:56 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static char	*ft_get_qut(char *line)
{
	t_line	*l;
	char	*temp;

	temp = NULL;
	l = ft_line_def();
	ft_putstr("quote>");
	while (ft_get_next_line(0, &l) > 0)
	{
		ft_lines_entered(&l);
		temp = ft_strjoin(line, l->line);
		ft_line_add(&l);
	}
	ft_putstr("OUT\n");
	if (line)
		free(line);
	return (temp);
}

char		*ft_check_qut(char *line)
{
	int		i;
	int		qut;
	char	*re;

	qut = 0;
	i = 0;
	re = line;
	while (line[i])
	{
		if (i == 0 && line[i] == '"')
			qut = 1;
		if (i > 0 && line[i] == '"' && line[i - 1] != '\\')
			qut = (qut == 0) ? 1 : 0;
		i++;
	}
	if (qut)
	{
		re = ft_get_qut(line);
		re = ft_check_qut(re);
	}
	return (re);
}
