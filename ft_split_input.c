/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 12:49:21 by rojones           #+#    #+#             */
/*   Updated: 2016/08/31 11:10:15 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

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
			data->env = ft_launch(temp, data);
			free(temp);
		}
		mv = col + 1;
	}
	temp = ft_strdup(mv);
	data->env = ft_launch(temp, data);
	if (temp)
		free(temp);
	return (data->env);
}
