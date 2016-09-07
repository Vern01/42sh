/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 12:49:21 by rojones           #+#    #+#             */
/*   Updated: 2016/09/07 11:51:14 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

char	*ft_check_logic_op(char *str, int *op)
{
	int 	i;
	int		s_qut;
	int		d_qut;

	i = 0;
	s_qut = 0;
	d_qut = 0;
	*op = 0;
	while (str && str[i] != '\0')
	{
		if (i == 0 && str[i] == '\'')
			s_qut = 1;
		if (i == 0 && str[i] == '"')
			d_qut = 1;
		if (str[i] == '"' && i > 0 && str[i - 1] != '\\' && s_qut == 0)
			d_qut = (d_qut == 0) ? 1 : 0;
		if (str[i] == '\'' && i > 0 && str[i - 1] != '\\' && d_qut == 0)
			s_qut = (s_qut == 0) ? 1 : 0;
		if (((str[i] == '|' && str[i + 1] == '|') ||
					(str[i] == '&' && str[i + 1] == '&'))
				&& s_qut == 0 && d_qut == 0)
		{
			*op = (str[i] == '|') ? 1 : 2;
			return (&str[i]);
		}
		i++;
	}
	return (NULL);
}

static int	run_comparison(t_data *data, t_split_log *log)
{
	if (log->init == 0)
		data->env = ft_launch(log->temp, data, &log->stat);
	else
	{
		printf("log->stat %d\n", log->stat);
		if (log->last_op == 1 && log->stat == 1)
			data->env = ft_launch(log->temp, data, &log->stat);
		else if (log->last_op == 2 && log->stat == 0)
			data->env = ft_launch(log->temp, data, &log->stat);
		else
		{
			ft_strdel(&log->temp);
			return (-1);
		}
	}
	ft_strdel(&log->temp);
	return (0);
}

char	**ft_split_input_op(char *line, t_data *data)
{
	t_split_log	log;

	log.mv = line;
	log.init = 0;
	log.stat = 0;
	while ((log.log = ft_check_logic_op(log.mv, &log.op)) != NULL)
	{
		if (log.log == line)
			return (data->env);
		log.temp = ft_strsub(log.mv, 0, (int)(log.log - log.mv));
		run_comparison(data, &log);
		log.last_op = log.op;
		log.init = 1;
		log.mv = log.log + 2;
	}
	log.temp = ft_strdup(log.mv);
	run_comparison(data, &log);
	return (data->env);
}

char	**ft_split_input(char *line, t_data *data)
{
	char	*col;
	char	*mv;
	char	*temp;

	mv = line;
	while ((col = ft_str_qut_char(mv, ';')) != NULL)
	{
		temp = ft_strsub(mv, 0, (int)(col - mv));
		if (temp)
		{
			data->env = ft_split_input_op(temp, data);
			free(temp);
		}
		mv = col + 1;
	}
	temp = ft_strdup(mv);
	data->env = ft_split_input_op(temp, data);
	ft_strdel(&temp);
	return (data->env);
}
