/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 10:20:08 by vivan-de          #+#    #+#             */
/*   Updated: 2016/07/29 10:52:42 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

void	ft_check_key(char **temp, char c, int *i)
{
	static int	counter = 0;

	if (c == 127 && *i-- != 0 && counter > 0)
	{
		*temp = ft_realloc(*temp, *i + 1);
		counter--;
	}
	if (ft_isprint(c))
	{
		*temp[*i] = c;
		counter++;
	}
}
