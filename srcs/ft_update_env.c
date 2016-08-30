/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oexall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 08:17:56 by oexall            #+#    #+#             */
/*   Updated: 2016/08/30 08:31:12 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <42sh.h>

int	ft_update_env(t_env *env, char *name, char *value)
{
	int	i;

	if (!name || !value)
		return (ft_error(1, "update_env", "Invalid Args"));
	i = -1;
	while (env->environ[++i])
		if (ft_strncmp(env->environ[i], name, ft_strlen(name)) == 0)
		{
			free(env->environ[i]);
			env->environ[i] = ft_chrjoin(name, value, '=');
			break ;
		}
	return (1);
}
