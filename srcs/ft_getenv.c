/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 07:27:16 by oexall            #+#    #+#             */
/*   Updated: 2016/08/30 07:35:49 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

char	*ft_getenv(char *name, t_env *env)
{
	int	i;

	i = -1;
	while (env->environ[++i])
	{
		if (ft_strncmp(env->environ[i], name, ft_strlen(name)) == 0)
			return (&env->environ[i][ft_strlen(name) + 1]);
	}
	return (NULL);
}


void	ft_print_env(t_env *env)
{
	int	i;

	i = -1;
	while (env->environ[++i])
		ft_putendl(env->environ[i]);
}
