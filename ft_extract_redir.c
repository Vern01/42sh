/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_redir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 13:51:27 by rojones           #+#    #+#             */
/*   Updated: 2016/09/06 10:56:10 by rojones          ###   ########.fr       */
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
	qut = 0;
	while (line[*i] && end == 0)
	{
		ft_check_arg_case_len(line, s_qut, d_qut, i);
		qut = (*s_qut || d_qut) ? 1 : 0;
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

static void	ft_init(t_getredir *tmp, int end)
{
	tmp->temp = NULL;
	tmp->temp2 = NULL;
	tmp->temp3 = NULL;
	tmp->temp4 = NULL;
	tmp->templine1 = NULL;
	tmp->templine2 = NULL;
	tmp->i = end + 1;
	tmp->s_qut = 0;
	tmp->d_qut = 0;
}

static void	ft_close(t_getredir *tmp, char **line)
{
	free(*line);
	*line = NULL;
	if (tmp->templine2[0] != '\0')
		*line = ft_strjoin(tmp->templine1, tmp->templine2);
	else
		*line = ft_strdup(tmp->templine1);
	if (tmp->temp)
		free(tmp->temp);
	if (tmp->temp2)
		free(tmp->temp2);
	if (tmp->temp3)
		free(tmp->temp3);
	if (tmp->temp4)
		free(tmp->temp4);
	if (tmp->templine1)
		free(tmp->templine1);
	if (tmp->templine2)
		free(tmp->templine2);
}

static int	ft_get_next_word(t_getredir *tmp, char **line, char **re)
{
	ft_skip_space(*line, &tmp->i);
	tmp->j = tmp->i;
	if (ft_inc_word(*line, &tmp->i, &tmp->s_qut, &tmp->d_qut))
	{
		ft_putstr_fd("Error: redirection peramiter missingi\n", 2);
		return (-1);
	}
	else
	{
		tmp->temp3 = ft_strsub(*line, tmp->j, tmp->i - tmp->j);
		tmp->temp4 = ft_strjoin(tmp->temp2, tmp->temp3);
		*re = ft_strjoin(tmp->temp, tmp->temp4);
	}
	tmp->templine2 = ft_strsub(*line, tmp->i, strlen(*line) - tmp->i);
	return (1);
}

char		*ft_extract_redir(char **line, char *redir, int st, int end)
{
	t_getredir	tmp;
	char		*re;

	ft_init(&tmp, end);
	re = NULL;
	tmp.templine1 = ft_strsub(*line, 0, st);
	if (redir)
		tmp.temp = ft_strjoin(redir, " ");
	tmp.temp2 = ft_strsub(*line, st, end - st);
	if (ft_isop(line[0][end - 1]) != 0)
	{
		if (ft_get_next_word(&tmp, line, &re) == -1)
			return (re);
	}
	else
	{
		re = ft_strjoin(tmp.temp, tmp.temp2);
		tmp.templine2 = ft_strsub(*line, end, ft_strlen(*line) - end);
	}
	ft_close(&tmp, line);
	return (re);
}
