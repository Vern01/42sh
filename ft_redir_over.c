/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redit_over.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 07:27:19 by rojones           #+#    #+#             */
/*   Updated: 2016/08/06 08:39:24 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

int	ft_redir_over(char *redir, char *op)
{
	int re;
	int	mv;

	if (*op == '>')
		re = 1;
	if (*op == '<')
		re = 0;
	if (op != redir)
	{
		mv = 0;
		while (redir[mv] && (redir[mv] == '-' || redir[mv] == '&') &&
				&redir[mv] != op)
			mv++;
		re = ft_atoi(&redir[mv]);
	}
	return (re);
}
