/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg_case_len.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 14:20:17 by rojones           #+#    #+#             */
/*   Updated: 2016/09/06 10:48:05 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

static void	ft_check_arg_case_len_i(char *line, int *s_qut, int *d_qut, int *i)
{
	if (line[*i] == '\\' && line[*i - 1] != '\\' && *s_qut == 0 && *d_qut == 0)
		*i = *i + 1;
	else if (line[*i] == '"' && line[*i - 1] != '\\' && *s_qut == 0)
	{
		*i = *i + 1;
		*d_qut = (*d_qut == 0) ? 1 : 0;
	}
	else if (line[*i] == '\'' && line[*i - 1] != '\\' && *d_qut == 0)
	{
		*i = *i + 1;
		*s_qut = (*s_qut == 0) ? 1 : 0;
	}
}

static void	ft_check_arg_case_len_z(char *line, int *s_qut, int *d_qut, int *i)
{
	if (line[*i] == '\\')
		*i = *i + 1;
	else if (line[*i] == '"' && *s_qut == 0)
	{
		*i = *i + 1;
		*d_qut = (d_qut == 0) ? 1 : 0;
	}
	else if (line[*i] == '\'' && *d_qut == 0)
	{
		*i = *i + 1;
		*s_qut = (s_qut == 0) ? 1 : 0;
	}
}

void		ft_check_arg_case_len(char *line, int *s_qut, int *d_qut,int *i)
{
	if (*i > 0)
		ft_check_arg_case_len_i(line, s_qut, d_qut, i);
	else
		ft_check_arg_case_len_z(line, s_qut, d_qut, i);
}
