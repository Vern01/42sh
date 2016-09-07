/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 16:49:16 by rojones           #+#    #+#             */
/*   Updated: 2016/09/07 07:25:20 by oexall           ###   ########.fr       */
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

char	**ft_unsetenv_err(t_data *data)
{
	ft_putstr("No args passed.");
	return (data->env);
}

char	**ft_unsetenv(char **split, t_data *data)
{
	int		rm;

	if (split[1] == NULL)
		return (ft_unsetenv_err(data));
	if (strcmp(split[0], "unset") == 0)
		ft_local_unset(data, split[1]);
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
