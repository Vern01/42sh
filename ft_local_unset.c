/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_local_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 07:10:43 by oexall            #+#    #+#             */
/*   Updated: 2016/09/07 14:53:45 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

int		ft_local_unset(t_data *data, char *name)
{
	int	rm;

	if (data->local == NULL || !name || !ft_get_local(data, name))
		return (1);
	rm = 0;
	while (data->local[rm])
	{
		if (ft_strncmp(data->local[rm], name, ft_strlen(name)) == 0)
		{
			free(data->local[rm]);
			if (data->local[rm + 1] == NULL)
				data->local[rm] = NULL;
			while (data->local[rm + 1])
			{
				data->local[rm] = data->local[rm + 1];
				data->local[rm + 1] = NULL;
				rm++;
			}
		}
		rm++;
	}
	return (1);
}
