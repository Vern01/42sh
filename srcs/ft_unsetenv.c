/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 09:11:13 by oexall            #+#    #+#             */
/*   Updated: 2016/08/30 09:27:04 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

int	ft_unsetenv(t_env *env, char *name)
{
	int	i;

	i = 0;
	if (!name)
		return (ft_error(1, "unsetenv", "Needs an Arguement"));
	while (env->environ[i])
	{
		if (ft_strncmp(env->environ[i], name, ft_strlen(name)) == 0)
		{
			free(env->environ[i]);
			while (env->environ[i + 1])
			{
				env->environ[i] = env->environ[i + 1];
				env->environ[i + 1] = NULL;
				i++;
			}
		}
		i++;
	}
	return (1);
}
