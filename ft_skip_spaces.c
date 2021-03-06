/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/02 08:12:09 by rojones           #+#    #+#             */
/*   Updated: 2016/07/20 17:50:51 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

void	ft_skip_space(char *line, int *i)
{
	while (line[*i] && ft_isspace(line[*i]) == 1)
		*i = *i + 1;
}
