/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 11:49:40 by oexall            #+#    #+#             */
/*   Updated: 2016/08/30 07:09:18 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

void	ft_init(t_env *env)
{
	env->environ = NULL;
}

int		main(int argc, char **argv, char **environ)
{
	t_env	env;

	(void)argc;
	(void)argv;
	ft_init(&env);
	ft_init_termcap(&env.win);
	ft_read_environ(&env, environ);
	ft_loop(&env);
	ft_free_environ(env.environ);
	ft_end_termcap(&env.win);
	return (0);
}
