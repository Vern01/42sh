/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 12:25:06 by oexall            #+#    #+#             */
/*   Updated: 2016/08/30 09:00:14 by oexall           ###   ########.fr       */
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

		//DEBUG
		ft_setenv(env, "NAME", "test", 0);
		ft_print_env(env);
		ft_setenv(env, "NAME", "owen", 1);
		ft_print_env(env);
	}
	return (1);
}
