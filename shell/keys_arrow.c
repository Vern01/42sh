/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_arrow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 00:44:15 by sasiedu           #+#    #+#             */
/*   Updated: 2016/09/09 10:22:38 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_up_key(t_term **sh)
{
	char	*line;

	if ((*sh)->current == NULL)
		(*sh)->current = ft_strdup((*sh)->line);
	line = ft_history_tower("UP", NULL);
	if (line == NULL)
		return ;
	ft_memset((*sh)->line, 0, MAX_LEN);
	ft_strcpy((*sh)->line, line);
	(*sh)->len = ft_strlen(line);
	(*sh)->my_cur = (*sh)->len;
	(*sh)->std_cur = (ft_strlen((*sh)->prt) + (*sh)->len);
	ft_reset_screen(&(*sh), (*sh)->my_cur, 0, 0);
	if (line != NULL)
		free(line);
}

void	ft_down_key(t_term **sh)
{
	char	*line;

	line = ft_history_tower("DOWN", NULL);
	if (line == NULL && (*sh)->current == NULL)
		return ;
	ft_memset((*sh)->line, 0, MAX_LEN);
	if (line == NULL)
	{
		ft_strcpy((*sh)->line, (*sh)->current);
		(*sh)->current = NULL;
	}
	else
		ft_strcpy((*sh)->line, line);
	(*sh)->len = ft_strlen((*sh)->line);
	(*sh)->my_cur = (*sh)->len;
	(*sh)->std_cur = (ft_strlen((*sh)->prt) + (*sh)->len);
	ft_reset_screen(&(*sh), (*sh)->my_cur, 0, 0);
	if (line != NULL)
		free(line);
}

void	ft_left_key(t_term **sh)
{
	if ((*sh)->my_cur > 0)
	{
		(*sh)->my_cur -= 1;
		(*sh)->std_cur -= 1;
		if ((*sh)->std_cur < 0)
			(*sh)->std_cur = tgetnum("co") - 1;
		ft_reset_screen(&(*sh), (*sh)->my_cur, 0, 0);
	}
}

void	ft_right_key(t_term **sh)
{
	if ((*sh)->my_cur < (*sh)->len)
	{
		(*sh)->my_cur += 1;
		(*sh)->std_cur += 1;
		if ((*sh)->std_cur >= tgetnum("co"))
			(*sh)->std_cur = 0;
		ft_reset_screen(&(*sh), (*sh)->my_cur, 0, 0);
	}
}
