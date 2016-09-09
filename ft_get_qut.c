/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_qut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 15:42:59 by rojones           #+#    #+#             */
/*   Updated: 2016/09/09 15:05:28 by rojones          ###   ########.fr       */
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
	ft_get_next_line(0, &l);
	temp = ft_strjoin(line, l->line);
	if (line)
		free(line);
	return (temp);
}

char		*ft_check_qut(char *line)
{
	int		i;
	int		d_qut;
	int		s_qut;
	char	*re;

	d_qut = 0;
	s_qut = 0;
	i = 0;
	re = line;
	while (line[i])
	{
		if (i == 0 && line[i] == '"')
			d_qut = 1;
		if (i > 0 && line[i] == '"' && line[i - 1] != '\\' && s_qut == 0)
			d_qut = (d_qut == 0) ? 1 : 0;
		if (i == 0 && line[i] == '\'')
			s_qut = 1;
		if (i > 0 && line[i] == '\'' && line[i - 1] != '\\' && d_qut == 0)
			s_qut = (s_qut == 0) ? 1 : 0;
		i++;
	}
	if (d_qut || s_qut)
	{
		re = ft_get_qut(line);
		re = ft_check_qut(re);
	}
	return (re);
}
