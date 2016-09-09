/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 15:51:36 by sasiedu           #+#    #+#             */
/*   Updated: 2016/09/09 16:31:07 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int		copy(t_term **sh)
{
	puts("+++++");
	ft_strncpy((*sh)->save, &(*sh)->line[(*sh)->i], (*sh)->my_cur);
	return (1);
}

int		cut(t_term **sh)
{
	int		i;
	int		j;

	ft_strncpy((*sh)->save, &(*sh)->line[(*sh)->i], (*sh)->my_cur);
	i = (*sh)->i;
	j = (*sh)->my_cur;
	(*sh)->my_cur = i;
	while (i++ < j)
		ft_remove_from_line(&(*sh));
	return (1);
}

int		paste(t_term **sh)
{
	int		i;
	int		len;

	i = -1;
	if (ft_strlen((*sh)->save) < 1)
		return (-1);
	len = ft_strlen((*sh)->save);
	while (++i < len)
	{
		(*sh)->buf[0] = (*sh)->save[i];
		ft_add_to_line(&(*sh));
	}
	return (0);
}
