/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 07:54:14 by oexall            #+#    #+#             */
/*   Updated: 2016/08/30 07:55:18 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

int		ft_error(int ret, char *cmd, char *err)
{
	ft_putstr(cmd);
	ft_putstr(": ");
	ft_putendl(err);
	return (ret);
}