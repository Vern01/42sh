/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_ctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasiedu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 03:48:46 by sasiedu           #+#    #+#             */
/*   Updated: 2016/09/07 15:07:32 by sasiedu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	ft_ctrl_home_key(t_term **sh, char *line, int i, int j)
{
	i = 0;
	j = 0;
	(*sh)->my_cur = prev_word(line, (*sh)->my_cur);
	(*sh)->std_cur = ((*sh)->my_cur + ft_strlen((*sh)->prt)) % tgetnum("co");
	ft_reset_screen(&(*sh), (*sh)->my_cur, 0, 0);
}

void	ft_ctrl_end_key(t_term **sh, char *line)
{
	(*sh)->my_cur = next_word(line, (*sh)->my_cur);
	(*sh)->std_cur = ((*sh)->my_cur + ft_strlen((*sh)->prt)) % tgetnum("co");
	ft_reset_screen(&(*sh), (*sh)->my_cur, 0, 0);
}
