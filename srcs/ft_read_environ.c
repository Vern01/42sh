/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_environ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 12:28:15 by oexall            #+#    #+#             */
/*   Updated: 2016/08/28 12:37:35 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

void	ft_free_environ(char **environ)
{
	int	i;

	if (environ)
	{
		i = 0;
		while (environ[i])
		{
			free(environ[i]);
			i++;
		}
		free(environ);
	}
}

void	ft_read_environ(t_env *env, char **environ)
{
	int	i;

	i = 0;
	while (environ[i])
		i++;
	env->environ = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (environ[i])
	{
		env->environ[i] = ft_strdup(environ[i]);
		i++;
	}
	env->environ[i] = NULL;
}
