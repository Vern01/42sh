/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 12:10:35 by rojones           #+#    #+#             */
/*   Updated: 2016/09/06 12:00:06 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static int	ft_inc_word(char *line, int *i, int *s_qut, int *d_qut)
{
	int end;
	int dig;
	int op;
	int	qut;

	end = 0;
	op = 0;
	dig = 1;
	while (line[*i] && end == 0)
	{
		ft_check_arg_case_len(line, s_qut, d_qut,  i);
		qut = (*s_qut || *d_qut) ? 1 : 0;
		if (ft_isdigit(line[*i]) == 0 && ft_isop(line[*i]) == 0
				&& line[*i] != '&')
			dig = 0;
		if (ft_isop(line[*i]) != 0 && qut == 0 && dig == 1)
			op = 1;
		if (line[*i] == '\0' || (ft_isspace(line[*i]) == 1 && qut == 0)
				|| (ft_isop(line[*i]) != 0 && qut == 0 && dig == 0))
			end = 1;
		else
			*i = *i + 1;
	}
	return (op);
}

char		*ft_get_redir(char **line)
{
	char	*re;
	int		s_qut;
	int		d_qut;
	int		i;
	int		j;

	i = 0;
	s_qut = 0;
	d_qut = 0;
	re = NULL;
	while (line[0][i] != '\0')
	{
		ft_skip_space(*line, &i);
		j = i;
		if (ft_inc_word(*line, &i, &s_qut, &d_qut))
		{
			re = ft_extract_redir(line, re, j, i);
			i = j - 1;
		}
	}
	return (re);
}
