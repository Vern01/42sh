/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 12:25:06 by oexall            #+#    #+#             */
/*   Updated: 2016/08/30 07:34:15 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

int		ft_loop(t_env *env)
{
	int	re;

	(void)env; //just for debugging purposes.
	re = 1;
	while (re)
	{
		ft_putstr(ft_getenv("USER", env));
		ft_putstr("$>");
		read(1, NULL, 1); //Just for debugging.
		ft_putchar('\n'); //Just for debugging.
	}
	return (1);
}
