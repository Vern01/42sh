/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 13:19:09 by rojones           #+#    #+#             */
/*   Updated: 2016/08/31 10:56:05 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

void	ft_exit(char **split, t_data *data)
{
	if (split)
		ft_free_str_arr(&split);
	ft_free_str_arr(&data->env);
	ft_restor_win(&data->win);
	ft_free_line(data->line);
	exit(0);
}
