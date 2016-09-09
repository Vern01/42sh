/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_redir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 09:08:45 by vivan-de          #+#    #+#             */
/*   Updated: 2016/09/09 09:23:49 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

void	ft_launch_redir(t_launch *lau)
{
	lau->splredir = ft_strsplit(lau->redir, ' ');
	ft_split_redir(lau->splredir, &lau->out, &lau->in);
}
