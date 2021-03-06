/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 16:37:32 by rojones           #+#    #+#             */
/*   Updated: 2016/08/05 13:07:53 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

int	ft_check_arg_op(char *str)
{
	if (ft_strcmp(">", str) == 0 || ft_strcmp(">>", str) == 0 ||
			ft_strcmp("<", str) == 0 || ft_strcmp("<<", str) == 0 ||
			ft_strcmp("|", str) == 0)
		return (1);
	return (0);
}
