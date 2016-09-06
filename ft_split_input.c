/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 12:49:21 by rojones           #+#    #+#             */
/*   Updated: 2016/09/06 12:25:21 by sasiedu          ###   ########.fr       */
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
