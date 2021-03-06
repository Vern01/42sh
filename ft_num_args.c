/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/01 16:26:27 by rojones           #+#    #+#             */
/*   Updated: 2016/09/09 09:27:11 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static int	ft_inc_word(char *line, int *i, int *s_qut, int *d_qut)
{
	int	end;
	int	re;
	int	qut;

	re = 0;
	end = 0;
	while (line[*i] && end == 0)
	{
		re = 1;
		ft_check_arg_case_len(line, s_qut, d_qut, i);
		qut = (*s_qut || *d_qut) ? 1 : 0;
		if (line[*i] == '\0' || (ft_isspace(line[*i]) == 1 && qut == 0) ||
				(ft_isop(line[*i]) == 1 && qut == 0))
			end = 1;
		else
			*i = *i + 1;
	}
	return (re);
}

int			ft_num_args(char *line)
{
	int		re;
	int		s_qut;
	int		d_qut;
	int		i;

	i = 0;
	s_qut = 0;
	d_qut = 0;
	re = 0;
	while (line[i] != '\0')
	{
		ft_skip_space(line, &i);
		re += ft_inc_word(line, &i, &s_qut, &d_qut);
		if (ft_isop(line[i]) == 1 && i > 0 && ft_isspace(line[i - 1]) == 0)
			re++;
		while (line[i] != '\0' && ft_isop(line[i]) == 1)
			i++;
	}
	return (re);
}
