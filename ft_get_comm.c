/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_comm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 09:41:54 by rojones           #+#    #+#             */
/*   Updated: 2016/09/07 14:38:24 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh21.h"

char	**ft_get_comm(char **split, t_data *data, int pipe)
{
	char	*path;
	int		block;

	path = NULL;
	block = 0;
	if (split[0])
	{
		if (strcmp(split[0], "exit") == 0)
			ft_exit(split, data);
		else if (strcmp(split[0], "echo") == 0)
			ft_echo(split, data->env);
		else if (strcmp(split[0], "cd") == 0 && ++block && pipe == 1)
			ft_cd(split, data);
		else if (strcmp(split[0], "setenv") == 0 && ++block && pipe == 1)
			ft_setenv(split, data);
		else if (strcmp(split[0], "unsetenv") == 0 && ++block && pipe == 1)
			data->env = ft_unsetenv(split, data);
		else if (strcmp(split[0], "env") == 0)
			ft_env(split, data->env);
		else if (block == 0 && (path = ft_search_path(split, data)) != NULL)
			execve(path, split, data->env);
		else if (block == 0)
			ft_printf("command not found: %s\n", split[0]);
		ft_strdel(&path);
	}
	return (data->env);
}
