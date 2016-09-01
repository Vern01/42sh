/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 12:10:35 by rojones           #+#    #+#             */
/*   Updated: 2016/08/05 14:35:10 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static int	ft_inc_word(char *line, int *i, int *qut)
{
	int end;
	int dig;
	int op;

	end = 0;
	op = 0;
	dig = 1;
	while (line[*i] && end == 0)
	{
		ft_check_arg_case_len(line, qut, i);
		if (ft_isdigit(line[*i]) == 0 && ft_isop(line[*i]) == 0
				&& line[*i] != '&')
			dig = 0;
		if (ft_isop(line[*i]) != 0 && *qut == 0 && dig == 1)
			op = 1;
		if (line[*i] == '\0' || (ft_isspace(line[*i]) == 1 && *qut == 0)
				|| (ft_isop(line[*i]) != 0 && *qut == 0 && dig == 0))
			end = 1;
		else
			*i = *i + 1;
	}
	return (op);
}

char		*ft_get_redir(char **line)
{
	char	*re;
	int		qut;
	int		i;
	int		j;

	i = 0;
	qut = 0;
	re = NULL;
	while (line[0][i] != '\0')
	{
		ft_skip_space(*line, &i);
		j = i;
		if (ft_inc_word(*line, &i, &qut))
		{
			re = ft_extract_redir(line, re, j, i);
			i = j - 1;
		}
	}
	return (re);
}
