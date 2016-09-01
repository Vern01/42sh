/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 16:49:16 by rojones           #+#    #+#             */
/*   Updated: 2016/08/31 13:03:24 by oexall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

char	**ft_rm_env_var(char **env, int rm_ind)
{
	int		i;
	int		off;
	char	**re;

	i = 0;
	off = 0;
	while (env[i])
		i++;
	if (!(re = (char **)malloc(sizeof(char*) * i)))
	{
		ft_putstr("malloc error");
		return (NULL);
	}
	i = 0;
	while (env[i])
	{
		if (i == rm_ind)
			off = -1;
		else
			re[i + off] = strdup(env[i]);
		i++;
	}
	re[i + off] = NULL;
	return (re);
}

char	**ft_unsetenv(char **split, t_data *data)
{
	int		rm;

	if (split[1] == NULL)
	{
		ft_putstr("no args passed");
		return (data->env);
	}
	rm = 0;
	while (data->env[rm])
	{
		if (ft_strncmp(data->env[rm], split[1], ft_strlen(split[1])) == 0)
		{
			free(data->env[rm]);
			if (data->env[rm + 1] == NULL)
				data->env[rm] = NULL;
			while (data->env[rm + 1])
			{
				data->env[rm] = data->env[rm + 1];
				data->env[rm + 1] = NULL;
				rm++;
			}
		}
		rm++;
	}
	return (data->env);
}
