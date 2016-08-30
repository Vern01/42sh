/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 07:49:11 by oexall            #+#    #+#             */
/*   Updated: 2016/08/30 08:00:07 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

int	ft_setenv(t_env *env, char *name, char *value, int reset)
{
	if (!name || !value)
		return (ft_error(1, "setenv", E_SETENV));
	return (1);
}
