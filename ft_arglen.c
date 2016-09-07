/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arglen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 14:21:13 by rojones           #+#    #+#             */
/*   Updated: 2016/09/06 13:09:31 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static void	ft_skipop(int *start, int *i, char *s)
{
	while (s[*start] != '\0' && ft_isop(s[*start]) != 0)
	{
		(*i)++;
		*start = *start + 1;
	}
}

int			ft_arglen(char *s, int *start)
{
	int i;
	int	s_qut;
	int	d_qut;

	i = 0;
	s_qut = 0;
	d_qut = 0;
	if (ft_isop(s[*start]) == 1)
		ft_skipop(start, &i, s);
	else
	{
		while (s[*start] != '\0')
		{
			ft_check_arg_case_len(s, &s_qut, &d_qut, start);
			if ((ft_isspace(s[*start]) == 1 || ft_isop(s[*start]) == 1) &&
					s_qut == 0 && d_qut == 0)
				return (i);
			i++;
			*start = *start + 1;
		}
	}
	return (i);
}
