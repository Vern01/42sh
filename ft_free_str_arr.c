/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 10:03:31 by rojones           #+#    #+#             */
/*   Updated: 2016/07/20 17:46:48 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

void	ft_free_str_arr(char **arr)
{
	int		i;

	if (arr)
	{
		i = 0;
		while (arr[i] != NULL)
		{
			if (arr[i])
				free(arr[i]);
			arr[i] = NULL;
			i++;
		}
		if (arr)
			free(arr);
	}
}
